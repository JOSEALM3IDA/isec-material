/*=========================== Cliente basico UDP ===============================
Este cliente destina-se a enviar mensagens passadas na linha de comando, sob
a forma de um argumento, para um servidor especifico cuja locacao e' dada
pelas seguintes constantes: SERV_HOST_ADDR (endereco IP) e SERV_UDP_PORT (porto)

O protocolo usado e' o UDP.
==============================================================================*/

#include <winsock.h>
#include <stdio.h>
 
#define SERV_HOST_ADDR "127.0.0.1"
#define SERV_UDP_PORT  6000

#define BUFFERSIZE     4096
#define TIMEOUT		   10000

void Abort(char *msg);

/*________________________________ main _______________________________________
*/

int main( int argc , char *argv[] )
{

	SOCKET sockfd;
	int msg_len, iResult, nbytes, cli_len, serv_check_len;
	struct sockaddr_in serv_addr,cli_addr, serv_check;
	char buffer[BUFFERSIZE];
	WSADATA wsaData;
	int i, ip_idx, port_idx, msg_idx;
	struct timeval timeout={TIMEOUT,0};
	int opt;

	/*========================= TESTA A SINTAXE =========================*/

	if(argc != 7){
		fprintf(stderr,"Sintaxe: %s -msg frase_a_enviar -ip ip_destino -port porto_destino \n",argv[0]);
		exit(EXIT_FAILURE);
	}

    for(i=0;i<7;i++)
	{
		if(!strcmp(argv[i],"-ip"))
		   ip_idx=i+1;
		if(!strcmp(argv[i],"-port"))
		   port_idx=i+1;
		if(!strcmp(argv[i],"-msg"))
		   msg_idx=i+1;   
		   
	}	
	/*=============== INICIA OS WINSOCKS ==============*/

	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		getchar();
		exit(1);
	}

	/*=============== CRIA SOCKET PARA ENVIO/RECEPCAO DE DATAGRAMAS ==============*/

	sockfd = socket( PF_INET , SOCK_DGRAM , 0 );
	if(sockfd == INVALID_SOCKET)
		Abort("Impossibilidade de criar socket");
		
	/*=============== ACTIVA POSSIBILIDADE DE ENVIO POR DIFUSAO ==============*/

	opt = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (char *)&opt, sizeof(opt));
	
		
	if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,(char *) &timeout,sizeof(timeout))==SOCKET_ERROR)	
		Abort("Impossibilidade de estabelecer timeout!");
	
	/*================= PREENCHE ENDERECO DO SERVIDOR ====================*/

	memset( (char*)&serv_addr , 0, sizeof(serv_addr) ); /*Coloca a zero todos os bytes*/
	serv_addr.sin_family = AF_INET; /*Address Family: Internet*/
	serv_addr.sin_addr.s_addr = inet_addr(argv[ip_idx]); /*IP no formato "dotted decimal" => 32 bits*/
	serv_addr.sin_port = htons(atoi(argv[port_idx])); /*Host TO Netowork Short*/

	/*====================== ENVIA MENSAGEM AO SERVIDOR ==================*/

	msg_len = strlen(argv[msg_idx]);

	if(sendto( sockfd , argv[msg_idx] , msg_len , 0 , (struct sockaddr*)&serv_addr , sizeof(serv_addr) ) == SOCKET_ERROR)
		Abort("SO nao conseguiu aceitar o datagram");
	

	printf("<CLI1>Mensagem enviada ...\n");

	cli_len=sizeof(cli_addr);
    if(getsockname( sockfd,(struct sockaddr *) &cli_addr,&cli_len)!=SOCKET_ERROR)
        printf("Porto local atribuido automaticamente:%d\n",ntohs(cli_addr.sin_port));		
	
	serv_check_len=sizeof(serv_check);
	nbytes=recvfrom(sockfd , buffer , sizeof(buffer) , 0 , (struct sockaddr*) &serv_check , &serv_check_len);

		if(nbytes == SOCKET_ERROR){
			if(WSAGetLastError()==WSAETIMEDOUT)
			   Abort("Timeout!");
			else
				Abort("Erro na recepcao de datagrams");
		}
		
		buffer[nbytes]='\0'; /*Termina a cadeia de caracteres recebidos com '\0'*/

		printf("\n<CLI1>Mensagem recebida {%s}\n",buffer);

		if((serv_check.sin_port==serv_addr.sin_port) && (!strcmp(inet_ntoa(serv_check.sin_addr),inet_ntoa(serv_addr.sin_addr))))
			printf("A mensagem veio do servidor!\n");
		else
			printf("A mensagem veio de um impostor!\n");

		

	/*========================= FECHA O SOCKET ===========================*/

	closesocket(sockfd);

	printf("\n");
	exit(EXIT_SUCCESS);
}

/*________________________________ Abort________________________________________
  Mostra uma mensagem de erro e o código associado ao ultimo erro com Winsocks. 
  Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE)
________________________________________________________________________________*/

void Abort(char *msg)
{

	fprintf(stderr,"<CLI1>Erro fatal: <%s> (%d)\n",msg, WSAGetLastError());
	exit(EXIT_FAILURE);

}
