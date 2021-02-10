/*=========================== Cliente basico UDP ===============================
Este cliente destina-se a enviar mensagens passadas na linha de comando, sob
a forma de um argumento, para um servidor especifico cuja localização é dada
pelas seguintes constantes: SERV_HOST_ADDR (endereço IP) e SERV_UDP_PORT (port)

O protocolo usado é o UDP.
==============================================================================*/

#include <winsock.h>
#include <stdio.h>
 
#define SERV_HOST_ADDR 	"127.0.0.1"
#define SERV_UDP_PORT  	6000

#define TIMEOUT				10000 // ms

#define BUFFERSIZE     		4096

void Abort(char *msg);

/*________________________________ main _______________________________________
*/

int main(int argc , char *argv[]) {
	struct timeval timeout = {TIMEOUT, 0}; // TIMEOUT ms + 0 usec
	SOCKET sockfd;
	int msg_len, iResult, nbytes, result, addr_len, i, ip_idx, port_idx, msg_idx, rec_serv_len, par_len;
	struct sockaddr_in serv_addr, rec_serv_addr;
	struct sockaddr_in addr; 	// Vai ser preenchida com a informação associada ao socket sockfd
	struct sockaddr_in par_addr;
	char buffer[BUFFERSIZE], msg[BUFFERSIZE];
	WSADATA wsaData;

	/*=============== INICIA OS WINSOCKS ==============*/

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		getchar();
		exit(1);
	}

	/*=============== CRIA SOCKET PARA ENVIO/RECEPCAO DE DATAGRAMAS ==============*/

	sockfd = socket(PF_INET, SOCK_DGRAM , 0);
	if (sockfd == INVALID_SOCKET)
		Abort("Impossibilidade de criar socket");

	/*=============== ESTABELECE O TIMEOUT DE ESPERA DA RESPOSTA ==============*/

	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout)) == SOCKET_ERROR)
		Abort("Impossibilidade de estabelecer timeout!");

	/*================= PREENCHE ENDERECO DO SERVIDOR ====================*/

	memset((char*)&serv_addr, 0, sizeof(serv_addr)); /* Coloca a zero todos os bytes */
	serv_addr.sin_family = AF_INET; /* Address Family: Internet */
	serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR); /* IP no formato "dotted decimal" => 32 bits */
	serv_addr.sin_port = htons(SERV_UDP_PORT); /* Host TO Network Short */

	/*====================== ENVIA MENSAGEM AO SERVIDOR ==================*/

	if (sendto(sockfd, NULL, 0, 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
		Abort("SO nao conseguiu aceitar o datagram");

	/*=============== PORTO LOCAL ATRIBUIDO AUTOMATICAMENTE ==============*/

	addr_len = sizeof(addr);
	if (getsockname(sockfd, (struct sockaddr*)&addr, &addr_len) != SOCKET_ERROR)
		printf("<CLI> Port local: {%d}\n", ntohs(addr.sin_port));

	/*===================== RECEBE MENSAGEM DO SERVIDOR ==================*/

	printf("<CLI> A espera do meu par...\n"); 

	rec_serv_len = sizeof(rec_serv_addr);
	par_len = sizeof(par_addr);
	nbytes = recvfrom(sockfd, (char*)&par_addr, par_len, 0, (struct sockaddr*)&rec_serv_addr, &rec_serv_len);

	if (nbytes == SOCKET_ERROR) 
		if (WSAGetLastError() == WSAETIMEDOUT) // Se o erro for causado pelo timeout
			Abort("Timeout");
		else
			Abort("Erro inesperado na leitura");


	/*============== VERIFICAR SE A MENSAGEM VEIO DO SERVIDOR ============*/
	
	if (strcmp(inet_ntoa(rec_serv_addr.sin_addr), SERV_HOST_ADDR) == 0  && ntohs(rec_serv_addr.sin_port) == SERV_UDP_PORT) {
		printf("<CLI2> O meu par tem IP {%s} e Port {%d}!\n", inet_ntoa(par_addr.sin_addr), ntohs(par_addr.sin_port));
		if (sendto(sockfd, NULL, 0, 0, (struct sockaddr*)&par_addr, sizeof(par_addr)) == SOCKET_ERROR)
			Abort("SO nao conseguiu aceitar o datagram");
	} else printf("<CLI1> O meu par tem IP {%s} e Port {%d}.\n", inet_ntoa(rec_serv_addr.sin_addr), ntohs(rec_serv_addr.sin_port));
	/*========================= FECHA O SOCKET ===========================*/

	closesocket(sockfd);
	exit(EXIT_SUCCESS);
}

/*________________________________ Abort________________________________________
  Mostra uma mensagem de erro e o código associado ao último erro com Winsocks. 
  Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE)
________________________________________________________________________________*/

void Abort(char *msg) {
	fprintf(stderr,"<CLI> Erro fatal: <%s> (%d)\n", msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}
