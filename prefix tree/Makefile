all:  trie.o main.o
	gcc -o trie obj/trie.o obj/main.o

trie.o: src/trie.c
	gcc -o obj/trie.o -c src/trie.c

main.o: src/main.c
	gcc -o obj/main.o -c src/main.c

