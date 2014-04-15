#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void test_simple() {
	trie* test = new trie;
	if (not (test->head->value == 0))
		throw failed;
}

int main() {
	int err = 0;
	err += test(test_simple);
	return err;
}
