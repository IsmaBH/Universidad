all:
	gcc -c Servidor.c Cliente.c
	gcc -c funciones.c
	gcc -c TADListaD.c
	gcc -c matrices.c
	gcc Servidor.o funciones.o TADListaD.o matrices.o -o Serv
	gcc Cliente.o funciones.o TADListaD.o matrices.o -o Client
