#include "trie.h"

int main() {
	struct trie *root;

	root = trie_insert(NULL,"bars", "60");
	root = trie_insert(root,"baribal", "100");
	root = trie_insert(root,"barabashka", "3000");
	root = trie_insert(root,"barsuk", "500");
	root = trie_insert(root,"barsik", "50");

	trie_print(root, 0);

	printf("Lookup 'bars': %s\n", trie_lookup(root, "bars"));
	root = trie_delete(root, "barabashka");
    printf("___________________\n");
	trie_print(root, 0);
	return 0;
}
