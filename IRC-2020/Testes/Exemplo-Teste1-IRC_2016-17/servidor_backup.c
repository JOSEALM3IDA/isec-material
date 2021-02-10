/*============================== Servidor UDP ==========================
  IRC 2016-17 - P6 - Teste sobre sockets UDP - Out./2016
  Jose' Marinho
========================================================================*/

#include <stdio.h>
#include <winsock.h>

#define SERV_UDP_PORT 5001
#define MAX_MSGS 5
#define TIMEOUT 60000; //msec
#define MAX_RESPONSE 100

void Abort(char *msg);

int main( int argc , char *argv[] )
{
	DWORD timeout;
	WSADATA wsaData;
	
	SOCKET s;
	int iResult, nbytes, size;
	int i, toContinue;
	struct sockaddr_in serv_addr , cli_addr;
	struct sockaddr_in sourceMsgs[MAX_MSGS];	
	char response[MAX_RESPONSE];
	double receivedValue, total, nReceivedMessages;
	
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		getchar();
		exit(1);
	}

	// a) Crie um socket UDP (uk: create an UDP socket)

	if((s = socket(/*...*/)) == /*...*/)
		Abort("Impossibilidade de abrir socket");

	memset( (char*)&serv_addr, 0, sizeof(serv_addr) );
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	// b) Preencha o campo relativo ao porto local pretendido 
	//	  (uk: appropriately set the value of field sin_port).

	serv_addr.sin_port = /*...*/(SERV_UDP_PORT);

	// c) Associe o socket ao porto pretendido
	//	  (uk: bind socket s to port SERV_UDP_PORT).

	if(bind(s , (struct sockaddr *)/*...*/, /*...*/) == SOCKET_ERROR){
		Abort("Impossibilidade de registar-se para escuta");		
	}

	while(1){

		fprintf(stderr,"\n<Servidor> Esperando nova vaga de doubles...\n\n");
		//(uk: started waiting for a new set of double values) 

		nReceivedMessages = 0;
		total = 0.0;
		toContinue = 1;

		// d) Desactive o timeout de recepcao no socket s
		//	  (uk: configure socket s with no receive timeout).

		timeout = /*...*/;
		setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, /*...*/, /*...*/);

		while(nReceivedMessages < MAX_MSGS && toContinue){

			// e) Aguarde pela recepcao de um datagrama UDP no socket s
			//    (uk: receive a datagram on socket s).
			//    O conteudo deve ser colocado na variavel receivedValue
			//	  (uk: the content of the received datagram, which is a double 
			//	  value in binary format, goes to the memory space where variable receivedValue
			//	  is kept).

			size = sizeof(cli_addr);
			nbytes=recvfrom(s, /*...*/receivedValue, /*...*/ , 0 , (struct sockaddr *)&cli_addr , &size);

			if(nbytes == SOCKET_ERROR){

				// f) Verifique se ocorreu algum timeout
				//	  (uk: check if any timeout has occured).

				if(/*...*/)
					toContinue = 0;
				else
					Abort("Erro na recepcao de datagramas");		

			}else{

				// g) Guarde as coordenadas da origem da mensagem na tabela sourceMsgs no indice
				//    com valor igual a nReceivedMessages 
				//	  (uk: save the coordinates/address of the source of the received message
				//	  in table sourceMsgs at index nReceivedMessages).

				/*...*/
				
				nReceivedMessages++
				total += receivedValue;

				printf("<Servidor> Valor recebido: %f\n", receivedValue);
				//(uk: <Server> Received value)

				if(nReceivedMessages == 1){

					// h) Active o timeout de recepcao com um valor definido pela constante TIMEOUT
					//	  (uk: from this point forward, receive operations must be subject to a 
					//	  timeout value defined by constant TIMEOUT).

					timeout = /*...*/;
					/*...*/;

				}

			}
			
		}

		// i) Construa a resposta de acordo com o solicitado no enunciado.
		//    Coloque a mensagem de texto resultante na variavel/string reposta.

		//	  (uk: define a string that indicates the number of received messages
		//	  and the sum of the double values they carried. Example: 
		//	  "Number of received messages: 10 ; Sum of values: 4274672.323") 

		sprintf_s(response, /*...*/, /*...*/, nReceivedMessages, total);

		for(i=0; i<nReceivedMessages; i++){

			// j) envie o conteudo da variavel response a cada um dos destinos presentes na tabela sourceMsgs
			//	  (uk: transmit the content of variable response, the previously defined string, to
			//	  all the destinations in table sourceMsgs).

			nbytes = sendto(s, response , /*...*/, 0 , (struct sockaddr *)/*...*/,sizeof(/*...*/));
		
			if (nbytes == SOCKET_ERROR){
				printf("\n<Servidor> Erro %d ao reenviar a mensagem 'a origem no indice %d da tabela\n", WSAGetLastError(), i);				
			}

		}
		
	}
	
}

/*________________________________ Abort________________________________________
  Mostra uma mensagem de erro e o codigo associado ao ultimo erro com Winsocks. 
  Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE)
________________________________________________________________________________*/

void Abort(char *msg)
{
	fprintf(stderr,"<Servidor> Erro fatal: <%s> (%d)\n",msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}