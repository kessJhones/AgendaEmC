all: app
app: funcoes.o main.o
	gcc -o app funcoes.o main.o
funcoes.o: funcoes.c
	gcc -o funcoes.o -c funcoes.c -W -Wall -pedantic
main.o: main.c funcoes.h
	gcc -o main.o -c main.c -W -Wall -pedantic
clean:
	rm -rf *.o
run:
	./app
