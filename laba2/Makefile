all: main.o bstree.o hashtab.o
	mv *.o obj/
	gcc -Wall -o laba obj/bstree.o obj/hashtab.o obj/main.o

gdb: main.o bstree.o hashtab.o
	gcc -Wall -g -O0 -o laba obj/bstree.o obj/hashtab.o obj/main.o

main.o: src/main.c
	gcc -c src/main.c

bstree.o: src/bstree.c
	gcc -c src/bstree.c
hashtab.o: src/hashtab.c
	gcc -c src/hashtab.c

