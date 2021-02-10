/*________________________________servidorTCPv1.c___________________________________*/
/*======================= Servidor interactivo TCP ============================
Este servidor destina-se mostrar mensagens recebidas via TCP, no porto
definido pela constante SERV_TCP_PORT.
Trata-se de um servidor que envia confirmacao (o comprimento, em bytes, da
mensagem recebida).
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>

#define SERV_TCP_PORT  6000
#define BUFFERSIZE     4096

void Abort(char *msg, SOCKET s);
void AtendeCliente(int sock);

/*________________________________ main ________________________________________
*/
int main(int argc, char *argv[]) {
	SOCKET sock = INVALID_SOCKET, newSock = INVALID_SOCKET;
	int iResult;
	int cliaddr_len;	
	struct sockaddr_in cli_addr,serv_addr;
	WSADATA wsaData;

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
	serv_addr.sin_port = htons(SERV_TCP_PORT);  /*Escuta no porto Well-Known*/

	/*====================== REGISTA-SE PARA ESCUTA =========================*/
	if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
		Abort("Impossibilidade de registar-se para escuta", sock);

	/*============ AVISA QUE ESTA PRONTO A ACEITAR PEDIDOS ==================*/
	if (listen(sock, 5) == SOCKET_ERROR) 
		Abort("Impossibilidade de escutar pedidos", sock);

	/*================ PASSA A ATENDER CLIENTES INTERACTIVAMENTE =============*/
	cliaddr_len = sizeof(cli_addr);
	while (1) {
		/*====================== ATENDE PEDIDO ========================*/
		if ((newSock = accept(sock, (struct sockaddr *)&cli_addr, &cliaddr_len)) == SOCKET_ERROR)
			fprintf(stderr, "<SERV> Impossibilidade de aceitar cliente...\n");
		else {
			AtendeCliente(newSock);
			closesocket(newSock);
		}
	}
}

/*___________________________ AtendeCliente ____________________________________
Atende cliente. 
______________________________________________________________________________*/

void AtendeCliente(int sock){
	static char buffer[BUFFERSIZE];
	static unsigned int cont = 0;
	int nbytes, nBytesSent;
		
	/*==================== PROCESSA PEDIDO ==========================*/
	switch((nbytes = recv(sock, buffer, BUFFERSIZE, 0))){

		case SOCKET_ERROR:
			fprintf(stderr, "\n<SER> Erro na recepcao de dados...\n");
			return;

		case 0:
			fprintf(stderr, "\n<SER> O cliente nao enviou dados...\n");
			return;

		default:
			buffer[nbytes] = '\0';
			printf("\n<SER> Mensagem n. %d recebida {%s}\n", ++cont, buffer);				
				
			/*============ ENVIA CONFIRMACAO =============*/
			printf("<SER> Confirma recepcao de mensagem.\n");
			//sprintf_s(buffer, BUFFERSIZE, "%d", nbytes);
			sprintf(buffer, "%d", nbytes);
			nbytes = strlen(buffer);

			if ((nBytesSent = send(sock, buffer, nbytes, 0)) == SOCKET_ERROR)
				fprintf(stderr, "<SER> Impossibilidade de Confirmar.\n");
			else if (nBytesSent < nbytes)
				fprintf(stderr, "<SER> Mensagem confirmada, mas truncada.\n");
			else 
				printf("<SER> Mensagem confirmada.\n");
	}
	
}

/*________________________________ Abort________________________________________
Mostra a mensagem de erro associada ao ultimo erro no SO e abando com 
"exit status" a 1
_______________________________________________________________________________
*/
void Abort(char *msg, SOCKET s) {
	fprintf(stderr,"\a<SER >Erro fatal: <%d>\n", WSAGetLastError());
	
	if(s != INVALID_SOCKET)
		closesocket(s);

	exit(EXIT_FAILURE);
}
