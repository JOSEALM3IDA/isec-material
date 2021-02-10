/*________________________________PROXY.C___________________________________*/
/*======================= Servidor concorrente Proxy =========================
Este servidor destina-se a servir de proxy para acesso a um determinado servidor.
O porto de escuta bem como o IP/nome e porto do servidor sao passados na linha
de comando.
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>

#define TIMEOUT 3
#define BUFFERSIZE	4096
#define MSG_BOAS_VINDAS "Servidor Casamenteiro\r\nAguarde...\r\n"
#define MSG_ARRANQUE_CONVERSA "Pode iniciar conversa com par...\r\n"

struct parSockets {
	SOCKET s1;
	SOCKET s2;
};

void AtendeCliente(LPVOID param);
int exchange(SOCKET s1, SOCKET s2);
void Abort(char *msg, SOCKET s);

struct sockaddr_in dest_addr;

/*________________________________ main ________________________________________
*/
int main(int argc, char *argv[])
{
	SOCKET sock = INVALID_SOCKET, newSock = INVALID_SOCKET;
	SOCKET parsock[2];
	int contador;
	struct parSockets *parametrosThreadAtendeCliente;
	int iResult;
	int cliaddr_len;
	struct sockaddr_in cli_addr, serv_addr, dest_addr;
	struct hostent *info;
	WSADATA wsaData;
	SECURITY_ATTRIBUTES sa;
	DWORD thread_id;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <porto de escuta>\n", argv[0]); 
		exit(EXIT_SUCCESS);
	}

	/*=============== INICIA OS WINSOCKS ==============*/
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		getchar();
		exit(1);
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
	if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
		Abort("Impossibilidade de registar-se para escuta", sock);

	/*============ AVISA QUE ESTA PRONTO A ACEITAR PEDIDOS ==================*/
	if (listen(sock, 5) == SOCKET_ERROR)
		Abort("Impossibilidade de escutar pedidos", sock);

	printf("<SER> Servidor casamenteiro pronto no porto de escuta: %s\n", argv[1]);

	/*========== PASSA A ATENDER CLIENTES DE FORMA CONCORRENTE  =============*/
	cliaddr_len = sizeof(cli_addr);
	contador = 0;
	while (1) {
		/*====================== ATENDE PEDIDO ========================*/
		if((newSock = accept(sock,(struct sockaddr *)&cli_addr,&cliaddr_len)) == SOCKET_ERROR){

			if(WSAGetLastError() == WSAEINTR)
				continue;

			fprintf(stderr,"<SER> Impossibilidade de aceitar cliente...\n");

		} else {
			printf("<SER> Novo cliente conectado: <%s:%d>.\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
			send(newSock, MSG_BOAS_VINDAS, strlen(MSG_BOAS_VINDAS), 0);
			parsock[contador++] = newSock;
			
			if (contador == 2) {
				contador = 0;

				parametrosThreadAtendeCliente = (struct parSockets*) malloc(sizeof(struct parSockets));

				if (parametrosThreadAtendeCliente == NULL) {
					printf("<SER> Nao foi possivel reservar espaco para passar parametros!\n");
					closesocket(parsock[0]);
					closesocket(parsock[1]);
				} else {
					parametrosThreadAtendeCliente->s1 = parsock[0];
					parametrosThreadAtendeCliente->s2 = parsock[1];

					sa.nLength = sizeof(sa);
					sa.lpSecurityDescriptor = NULL;

					if (CreateThread(&sa, 0, (LPTHREAD_START_ROUTINE)AtendeCliente, (LPVOID)parametrosThreadAtendeCliente, (DWORD)0, &thread_id)==NULL){
						printf("<SER> Nao foi possivel iniciar uma nova thread (erro: %d)\n", GetLastError());			
						printf("<SER> O cliente <%s:%d> nao sera' atendido\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
						closesocket(parsock[0]);
						closesocket(parsock[1]);
					}

					printf("<SER> Um novo par acaba de ser formado.\n");
				}
			}
		}
	}
}

/*___________________________ AtendeCliente ____________________________________
Atende cliente.
______________________________________________________________________________*/

void AtendeCliente(LPVOID param)
{
	SOCKET sockCli1, sockCli2;
	struct parSockets *p;
	fd_set fdread, fdtemp;

	p = (struct parSockets*) param;
	sockCli1 = p->s1;
	sockCli2 = p->s2;
	free(p);

	send(sockCli1, MSG_ARRANQUE_CONVERSA, strlen(MSG_ARRANQUE_CONVERSA), 0);
	send(sockCli2, MSG_ARRANQUE_CONVERSA, strlen(MSG_ARRANQUE_CONVERSA), 0);

	//Limpa fdread
	FD_ZERO(&fdread);

	//Coloca sockCli e sockDest em fdread
	FD_SET(sockCli1, &fdread);
	FD_SET(sockCli2, &fdread);

	while (1) {
		/*==================== PROCESSA PEDIDO ==========================*/

		fdtemp = fdread;

		switch (select(32, &fdtemp, NULL, NULL, NULL)) { // Sem timeout
			case SOCKET_ERROR:
				if(WSAGetLastError()==WSAEINTR)
					break;

				fprintf(stderr,"<SER_%d> Erro na rotina select (%d) ...\n", GetCurrentThreadId(), WSAGetLastError());
				closesocket(sockCli1);
				closesocket(sockCli2);
				return;

			default:
				//Testa sockCli1 para leitura nao bloqueante 
				if (FD_ISSET(sockCli1, &fdtemp)) {
					if(exchange(sockCli1, sockCli2) <= 0){
						closesocket(sockCli1);
						closesocket(sockCli2);
						return;
					}
				}

				//Testa sockCli2 para leitura nao bloqueante
				if (FD_ISSET(sockCli2, &fdtemp)){
					if(exchange(sockCli2, sockCli1) <= 0){
						closesocket(sockCli2);
						closesocket(sockCli1);
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
