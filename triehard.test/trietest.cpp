#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void test_simple() {
	trie test;
	test.head = node(NULL, 0);
	test.head.neighbors.push_back(node('k', 1));
	if (not (test.head.neighbors[0].value == 1))
		throw failed;
}

int main() {
	int err = 0;
	err += test(test_simple);
	return err;
}
