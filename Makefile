CC=gcc
CFLAGS= -Wno-implicit-function-declaration

all: final

final: main.o
	$(CC) $(CFLAGS) main.o -o main
	chmod +x ./main

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

clean:
	rm main.o main
