// a) crie um socket TCP
	if((sock=socket( PF_INET , /*...*/SOCK_STREAM , /*...*/IPPROTO_TCP )) == INVALID_SOCKET)
		Abort("Impossibilidade de abrir socket", sock);

//b) utilize o porto passado na linha de comandos
	serv_addr.sin_port=htons(/*...*/atoi(argv[1]));  /*Escuta no porto Well-Known*/

//c) registe o servidor para escuta no porto definido
	if(bind(/*...*/sock,/*...*/(struct sockaddr *)&serv_addr,/*...*/sizeof(serv_addr)) == SOCKET_ERROR)
		
// d) defina o número mínimo de clientes, antes de activar o timeout
		if(/*...*/contador >= 2){
			
// e) defina o timeout usando a função select e as variáveis fd_accept e tempoEspera
			FD_ZERO(/*...*/&fd_accept);
			FD_SET(/*..*/sock, &fd_accept);
			
			switch(select(32, /* ...*/&fd_accept, /* ...*/NULL,/* ...*/NULL,/* ...*/&tempoEspera)){
				
// f) Atende pedidos de ligação
			if((/*...*/newSock=accept(sock,/* ...*/(struct sockaddr *)&cli_addr,/* ...*/&cliaddr_len)) == SOCKET_ERROR){
			
//g) Envie a mensagem de boas vindas ao cliente, definida na constante MSG_BOAS_VINDAS
			/*...*/
			send(newSock, MSG_BOAS_VINDAS, strlen(MSG_BOAS_VINDAS), 0);
			
//h) Construa a mensagem com identifador do número do cliente e envie-a ao cliente
			sprintf(cliente_id_msg,/* ...*/"%d",/* ...*/ntohs(cli_addr.sin_port));
			send(/* ...*/newSock,/* ...*/cliente_id_msg,/* ...*/cliente_id_msg,0);
			grupoSockets[contador++] = newSock;

// i) Envie a todos os cliente ligados a mensagem de arranque de conversa (definida na constante MSG_ARRANQUE_CONVERSA
	for(i=0; i</*..*/MAX_TAM_GRUPO; i++){
		send(/*..*/grupo[i], /*..*/MSG_ARRANQUE_CONVERSA, /*..*/strlen(MSG_ARRANQUE_CONVERSA), 0);
	}

// j) Inicie fdread de modo a poder testar os diversos sockets para efeitos de leitura
	/*...*/FD_ZERO(&fdread);
	for(i=0; i</*..*/MAX_TAM_GRUPO; i++){
		/*..*/
		if (grupo[i] != INVALID_SOCKET) {
			FD_SET(grupo[i], &fdread);
		}
	}

//k) Invoque a função select, passando-lhe fdtemp, sem tempo limite de espera

		switch(/*..*/select(32, &fdtemp, NULL, NULL, NULL)){ // Sem timeout
		//switch(select(32, &fdtemp, NULL, NULL, &timeout)){
			
// l) teste os diversos sockets para efeitos de leitura
				for(i=0; i</*...*/MAX_TAM_GRUPO; i++){
					if(/*...*/grupo[i] != INVALID_SOCKET){

// m) Inicialize a variável contadora de mensagens
	for(i=0;i<MAX_TAM_GRUPO;i++)
		if (/*..*/grupo[i] != INVALID_SOCKET && tam != i)
			n_msg[i]=/*...*/sock_number;
		
// n) Receba bytes em origem e		
	if((result=recv(origem, /*...*/&c,/*...*/sizeof(char), 0))==sizeof(char)){
		   for(i=0; i<tam; i++){
			   if(origem!=grupo[i]){
				   
// o) teste se o cliente destino é par e se o número da mensagem a enviar é também par e envie os bytes recebidos
					if(/*...*/(tam%2) == 0 && /*...*/(n_msg[i]%2) == 0 ){
						result=send(grupo[i], (char *)c,sizeof(c), 0);
					}

// p) teste se o cliente destino é impar e se o número da mensagem a enviar é também impar e envie os bytes recebidos				
					if(/*...*/(tam%2) != 0 && /*...*/(n_msg[i]%2) != 0){
						result=send(grupo[i],(char *)c,sizeof(c), 0);
					
// q)  Caso tenha recebido uma mensagem completa, incremente o contador de mensagens para esse cliente
		if(/*...*/result == sizeof(c)){
			n_msg[/*...*/i]+=1;
		}