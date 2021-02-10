all: cliente servidor
	@ echo "Tarefa concluida."

cliente: cliente.c
	@ gcc cliente.c -o cliente.exe -lws2_32
	@ echo "Cliente compilado."
	
servidor: servidor.c
	@ gcc servidor.c -o servidor.exe -lws2_32
	@ echo "Servidor compilado."

clean:
	@ rm cliente.exe
	@ rm servidor.exe
	@ echo "Diretorio limpo."