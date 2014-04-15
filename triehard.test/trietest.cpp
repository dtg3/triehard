#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void test_simple() {
	trie* test = new trie;
	std::cerr << "TRIE CREATION\n";
	if (not (test->head->value == 0))
		throw failed;
	
	test->add("foo", 1);
	std::cerr << "TRIE INSERTION\n";
	if (not (test->find("foo") == true))
		throw failed;
	if (not (test->find("food") == false))
		throw failed;
}

int main() {
	int err = 0;
	err += test(test_simple);
	return err;
}
