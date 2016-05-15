all: llist.o queue.o binary_heap.o graph.o main.o
	gcc -o graph -std=c99 obj/llist.o obj/queue.o obj/binary_heap.o obj/graph.o obj/main.o

llist.o: src/llist.c
	gcc -o obj/llist.o -std=c99 -c src/llist.c

queue.o: src/queue.c
	gcc -o obj/queue.o -std=c99 -c src/queue.c

binary_heap.o: src/binary_heap.c
	gcc -o obj/binary_heap.o -std=c99 -c src/binary_heap.c

graph.o: src/graph.c
	gcc -o obj/graph.o -std=c99 -c src/graph.c

main.o: src/main.c
	gcc -o obj/main.o -std=c99 -c src/main.c

