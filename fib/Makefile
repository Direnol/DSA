all: obj/fib.o obj/main.o
	gcc -o fib -std=c99 obj/fib.o obj/main.o -lm

obj/fib.o: src/fib.c
	gcc -o fib.o -std=c99 -c src/fib.c
	mv fib.o obj/

obj/main.o: src/main.c
	gcc -o main.o -std=c99 -c src/main.c
	mv main.o obj/
