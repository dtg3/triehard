#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_init() {
	trie* test = new trie;
	std::cerr << "TRIE CREATION\n";
	if (not (test->head->value == NULL))
		throw failed;
}

int main() {
	int err = 0;
	err += test(trie_init);
	return err;
}
