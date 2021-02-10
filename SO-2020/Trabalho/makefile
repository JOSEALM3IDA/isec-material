CC = gcc -W -pthread
GAMES = $(patsubst %.c, %, $(wildcard Games/g_*.c))

all: arbitro cliente jogos
	@ echo "Tarefa concluida."

debug: arbitro-debug cliente-debug
	@ echo "Compilacao para debug concluida."

# SECCAO CLIENTE
# compila para object e depois para executável

cliente: cliente.o utils.o
	@ $(CC) $^ -o $@
	@ echo "Programa cliente compilado."

cliente.o: cliente.c cliente.h utils.h
	@ $(CC) -c $< -o $@

cliente-debug: cliente.c cliente.h utils-debug
	@ $(CC) -g -c ./cliente.c -o ./cliente.o
	@ $(CC) -g ./cliente.o ./utils.o -o ./cliente
	@ echo "Programa cliente compilado."

# SECCAO ARBITRO
# compila para object e depois para executável

arbitro: arbitro.o utils.o
	@ $(CC) $^ -o $@
	@ echo "Programa árbitro compilado."

arbitro.o: arbitro.c arbitro.h utils.h
	@ $(CC) -c $< -o $@

arbitro-debug: arbitro.c arbitro.h utils-debug
	@ $(CC) -g -c ./arbitro.c -o ./arbitro.o
	@ $(CC) -g ./arbitro.o ./utils.o -o ./arbitro
	@ echo "Programa árbitro compilado."

# SECCAO UTILS
# compila para object

utils.o: utils.c utils.h
	@ $(CC) -c $< -o $@

utils-debug: utils.c utils.h
	@ $(CC) -g -c $< -o utils.o

# SECCAO JOGO
# compila para object e depois para executável

jogos: $(GAMES)

g_%: g_%.o
	@ $(CC) $< -o $@
	@ echo "Jogo $(patsubst Games/g_%,%, $@) compilado."

g_%.o: g_%.c
	@ $(CC) -c $< -o $@

# workaround para fazer com que objetos intermédios (neste casos, os ficheiro objeto dos jogos) não sejam automaticamente apagados
.SECONDARY: 

# SECCAO MANUTENCAO
# limpa o diretorio de ficheiros temporarios e/ou de executaveis

clean: clean-obj clean-exe
	@ echo "Diretorio limpo."

clean-obj:
	@ rm *.o -f
	@ rm ./Games/*.o -f

clean-exe:
	@ rm ./arbitro ./cliente -f
	@ rm $(GAMES) -f

clean-pipes:
	@ echo "Pipes deixados por problemas de execução eliminados."
	@ rm *_w *_r arb_pipe -f