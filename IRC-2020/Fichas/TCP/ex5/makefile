all: servidor
	@ echo "Tarefa concluida."

servidor: servidor.c
	@ gcc servidor.c -o servidor.exe -lws2_32
	@ echo "Servidor compilado."

clean:
	@ rm servidor.exe
	@ echo "Diretorio limpo."