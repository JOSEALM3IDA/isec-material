/*________________________________PROXY.C___________________________________*/
/*======================= Servidor concorrente Proxy =========================
Este servidor destina-se a servir de proxy para acesso a um determinado servidor.
O porto de escuta bem como o IP/nome e porto do servidor sao passados na linha
de comando.
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>

#define BUFFERSIZE	4096

void AtendeCliente(LPVOID param);
int exchange(SOCKET s1, SOCKET s2);
void Abort(char *msg, SOCKET s);

struct sockaddr_in dest_addr;

/*________________________________ main ________________________________________
*/
int main(int argc, char *argv[])
{
	SOCKET sock = INVALID_SOCKET, newSock = INVALID_SOCKET;
	int iResult;
	int cliaddr_len;
	struct sockaddr_in cli_addr, serv_addr	;
	struct hostent *info;
	WSADATA wsaData;
	SECURITY_ATTRIBUTES sa;
	DWORD thread_id;

	if (argc != 4) {
		fprintf(stderr, "Usage: %s <porto de escuta> <maquina destino> <porto destino>\n", argv[0]); 
		exit(EXIT_SUCCESS);
	}

	/*=============== INICIA OS WINSOCKS ==============*/
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		getchar();
		exit(1);
	}

	/*===== PREENCHE A ESTRUTURA DE ENDERECO PARA O SERVIDOR ============*/
	memset((char *)&dest_addr, 0, sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(atoi(argv[3]));
	dest_addr.sin_addr.s_addr = inet_addr(argv[2]);

	//Resolve o nome caso seja necessario ...
	if (dest_addr.sin_addr.s_addr == INADDR_NONE){
		if ((info = gethostbyname(argv[2])) == NULL)
			Abort("Host desconhecido", sock);
		else
			memcpy(&(dest_addr.sin_addr.s_addr), info->h_addr, info->h_length);
	}

	/*================== ABRE SOCKET PARA ESCUTA DE CLIENTES ================*/
	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		Abort("Impossibilidade de abrir socket", sock);

	/*=================== PREENCHE ENDERECO DE ESCUTA =======================*/
	memset((char*)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /*Recebe de qq interface*/
	serv_addr.sin_port = htons(atoi(argv[1]));  /*Escuta no porto Well-Known*/

	/*====================== REGISTA-SE PARA ESCUTA =========================*/
	if (bind(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) == SOCKET_ERROR)
		Abort("Impossibilidade de registar-se para escuta", sock);

	/*============ AVISA QUE ESTA PRONTO A ACEITAR PEDIDOS ==================*/
	if(listen(sock, 5) == SOCKET_ERROR)
		Abort("Impossibilidade de escutar pedidos", sock);

	printf("<SER> Servidor proxy pronto no porto de escuta: %s\n", argv[1]);
	printf("<SER> A fazer de \"ponte\" para: <%s:%s>\n\n", argv[2], argv[3]);

	/*========== PASSA A ATENDER CLIENTES DE FORMA CONCORRENTE  =============*/
	cliaddr_len = sizeof(cli_addr);
	while (1) {
		/*====================== ATENDE PEDIDO ========================*/
		if ((newSock = accept(sock, (struct sockaddr *)&cli_addr, &cliaddr_len)) == SOCKET_ERROR){

			if (WSAGetLastError() == WSAEINTR)
				continue;

			fprintf(stderr, "<SER> Impossibilidade de aceitar cliente...\n");

		} else {
			sa.nLength = sizeof(sa);
			sa.lpSecurityDescriptor = NULL;
			if (CreateThread(&sa,0 ,(LPTHREAD_START_ROUTINE)AtendeCliente, (LPVOID)newSock, (DWORD)0, &thread_id)==NULL){
				printf("<SER> Nao foi possivel iniciar uma nova thread (erro: %d)\n", GetLastError());			
				printf("<SER> O cliente <%s:%d> nao sera' atendido\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
				closesocket(newSock);
			}

			printf("<SER> Cliente <%s:%d> atendido pela thread com id: %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), thread_id);
		}
	}
}

/*___________________________ AtendeCliente ____________________________________
Atende cliente.
______________________________________________________________________________*/

void AtendeCliente(LPVOID param)
{
	SOCKET sockCli, sockDest; // sockDest: socket para comunicar como o servidor
	fd_set fdread, fdtemp;

	sockCli = (SOCKET)param;

	//Cria o socket para comunicar com o servidor
	if ((sockDest = socket(PF_INET, SOCK_STREAM, IPPROTO_IP)) == SOCKET_ERROR) {
		fprintf(stderr,"<SER_%d> Erro na criacao do socket para comunicar com o servidor (%d)...\n", GetCurrentThreadId(), WSAGetLastError());
		closesocket(sockCli);
		return;
	}

	//Liga o socket ao servidor
	if (connect(sockDest, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == SOCKET_ERROR) {
		fprintf(stderr, "<SER_%d> Erro na ligacao ao servidor (%d)...\n", GetCurrentThreadId(), WSAGetLastError());	
		closesocket(sockCli); closesocket(sockDest);
		return;
	}

	//Limpa fdread
	FD_ZERO(&fdread);

	//Coloca sockCli e sockDest em fdread
	FD_SET(sockCli, &fdread);
	FD_SET(sockDest, &fdread);

	while (1) {
		/*==================== PROCESSA PEDIDO ==========================*/
		fdtemp = fdread;

		switch (select(32, &fdtemp, NULL, NULL, NULL)) { // Sem timeout
			case SOCKET_ERROR:
				if(WSAGetLastError()==WSAEINTR)
					break;

				fprintf(stderr,"<SER_%d> Erro na rotina select (%d) ...\n", GetCurrentThreadId(), WSAGetLastError());
				closesocket(sockCli); closesocket(sockDest);
				return;

			default:
				//Testa sockCli para leitura nao bloqueante 
				if (FD_ISSET(sockCli, &fdtemp)) {
					if(exchange(sockCli, sockDest) <= 0){
						closesocket(sockCli);
						closesocket(sockDest);
						return;
					}
				}

				//Testa sockDest para leitura nao bloqueante
				if (FD_ISSET(sockDest, &fdtemp)){
					if(exchange(sockDest, sockCli) <= 0){
						closesocket(sockDest);
						closesocket(sockCli);
						return;
					}
				}

				break;
		} //switch
	} //while
}

/*_____________________________ exchange _______________________________________
Recebe um caractere do primeiro socket e escreve-o no segundo

Devolve:
	SOCKET_ERROR : se houve erro
			   0 : EOF
	        >= 0 : se leu algum byte
______________________________________________________________________________*/
int exchange(SOCKET s1, SOCKET s2)
{
	int result;
	char c;

	//Recebe um char em s1 e escreve-o em s2
	
	if (result = recv(s1, &c, sizeof(char), 0) != SOCKET_ERROR)
		result = send(s2, &c, sizeof(char), 0);

	return result;
}

/*________________________________ Abort________________________________________
Mostra a mensagem de erro associada ao ultimo erro dos Winsock e abandona com 
"exit status" a 1
_______________________________________________________________________________
*/
void Abort(char *msg, SOCKET s)
{
	fprintf(stderr,"\a<SER_%d> Erro fatal: <%d>\n",  GetCurrentThreadId(), msg, WSAGetLastError());
	
	if(s != INVALID_SOCKET)
		closesocket(s);

	exit(EXIT_FAILURE);
}
