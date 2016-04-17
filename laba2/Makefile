all: main.o bstree.o hashtab.o
	gcc -Wall -o laba obj/bstree.o obj/hashtab.o obj/main.o

gdb: main.o bstree.o hashtab.o
	gcc -Wall -g -O0 -o laba obj/bstree.o obj/hashtab.o obj/main.o

main.o: src/main.c
	gcc -c src/main.c
	mv main.o obj/

bstree.o: src/bstree.c
	gcc -c src/bstree.c
	mv bstree.o obj/

hashtab.o: src/hashtab.c
	gcc -c src/hashtab.c
	mv hashtab.o obj/
