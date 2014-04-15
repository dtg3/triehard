#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_insert_find() {
	trie* test = new trie;
	test->add("foo", 1);
	if (not (test->find("foo") == true))
		throw failed;
	if (not (test->find("food") == false))
		throw failed;

	test->add("food", 2);
	if (not (test->find("food") == true))
		throw failed;

	test->add("butterscotch", 4);
	if (not (test->find("butter") == true))
		throw failed;	
	if (not (test->find("butters") == true))
		throw failed;	
	if (not (test->find("butterscotch") == true))
		throw failed;
}

int main() {
	int err = 0;
	err += test(trie_insert_find);
	return err;
}
