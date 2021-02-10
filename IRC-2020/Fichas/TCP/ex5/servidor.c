/*________________________________servidorTCP_Concorrente.c___________________________________*/
/*======================= Servidor concorrente TCP ============================
Este servidor destina-se mostrar mensagens recebidas via TCP, no porto
definido pela constante SERV_TCP_PORT.
Trata-se de um servidor que envia confirmacao (o comprimento, em bytes, da
mensagem recebida). 

Concorrente --> atende varios clientes em "simultaneo".

O atendimento de um determinado cliente termina quando a ligacao deixa de estar
operacional ou quando e' recebida a sequencia de caracteres definida
pela constante EXIT.
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>

#define SERV_TCP_PORT  6000
#define BUFFERSIZE     4096
#define EXIT	"EXIT"

void Abort(char *msg, SOCKET s);
void AtendeCliente(LPVOID param);
int writeN(SOCKET sock, char* buff, int nbytes);
int readLine(SOCKET sock, char* buff, int n);

/*________________________________ main ________________________________________
*/
int main(int argc, char *argv[]) {
	SOCKET sock = INVALID_SOCKET, newSock = INVALID_SOCKET;
	int iResult;
	int cliaddr_len;	
	struct sockaddr_in cli_addr,serv_addr;
	WSADATA wsaData;
	SECURITY_ATTRIBUTES sa;
	DWORD thread_id;

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
			sa.nLength = sizeof(sa);
			sa.lpSecurityDescriptor = NULL;
			if (CreateThread(&sa, 0, (LPTHREAD_START_ROUTINE)AtendeCliente, (LPVOID)newSock, (DWORD)0, &thread_id) == NULL) {
				printf("<SERV> Nao foi possivel atender o cliente\n");
				closesocket(newSock);
			}
		}
	}
}

/*___________________________ AtendeCliente ____________________________________
Atende cliente. 
______________________________________________________________________________*/

void AtendeCliente(LPVOID param) {
	char msg[BUFFERSIZE], resposta[BUFFERSIZE];
	static unsigned int cont=0;
	int nbytes, nBytesSent;
	SOCKET sock;
	struct sockaddr_in cli_addr;

	sock = (SOCKET)param;
	
	nbytes = sizeof(cli_addr);
	if(getpeername(sock, (struct sockaddr *)&cli_addr,&nbytes) != SOCKET_ERROR)
		printf("<SER> Sou a thread com id %d e vou atender o cliente <%s : %d>\n", GetCurrentThreadId(), inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
		
	do {
		/*==================== PROCESSA PEDIDO ==========================*/
		switch((nbytes = readLine(sock, buffer, BUFFERSIZE))){
			case SOCKET_ERROR:
				fprintf(stderr, "\n<SER> Erro na recepcao de dados...\n");
				return;

			case 0:
				fprintf(stderr, "\n<SER> O cliente nao enviou dados...\n");
				return;

			default:
				buffer[nbytes] = '\0';
				printf("\n<SER> Mensagem n. %d recebida {%s}\n", ++cont, buffer);	
				if (strcmp(buffer, "SAIR") == 0) {
					printf("\n<SERV> Cliente processado.\n");
					return;
				}			
					
				/*============ ENVIA CONFIRMACAO =============*/
				printf("<SER> Confirma recepcao de mensagem.\n");
				//sprintf_s(buffer, BUFFERSIZE, "%d", nbytes);
				sprintf(buffer, "%d", nbytes);
				nbytes = strlen(buffer);

				if ((nBytesSent = writeN(sock, buffer, nbytes)) == SOCKET_ERROR)
					fprintf(stderr, "<SER> Impossibilidade de Confirmar.\n");
				else 
					printf("<SER> Mensagem confirmada.\n");
		}
		
		if(strcmp(msg, EXIT)==0){
			printf("<SER_%d> E' para terminar...\n", GetCurrentThreadId());
			break;
		}
	} while (nbytes > 0);
		
	closesocket(sock);
}

int writeN(SOCKET sock, char* buff, int nbytes) {
	int nLeft = nbytes + 1, nWritten;
	while (nLeft > 0) {
		if ((nWritten = send(sock, buff, nLeft, 0)) == SOCKET_ERROR)
			return nWritten;
		else {
			nLeft -= nWritten;
			buff += nWritten;
		}
	}

	send(sock, "\n", sizeof(char), 0);

	return nWritten;
}

int readLine(SOCKET sock, char* buff, int nbytes) {
	char c;
	int i = 0, nRead;
	while (i < nbytes - 1) {
		if ((nRead = recv(sock, &c, sizeof(c), 0)) == SOCKET_ERROR)
			return nRead;
			
		else if (nRead == 0)
			break;

		if (c == '\r')
			continue;
		else if (c == '\n')
			break;
		else
			buff[i++] = c;
	}

	return i;
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
