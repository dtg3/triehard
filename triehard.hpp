#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <vector>

struct node {
	char id;
	std::vector<node> neighbors;
	int value;
	
	node() {}
	node(const char& letter, const int& val) {
		id = letter;
		value = val;
	}
};

struct trie {
	node head = node(NULL,0);
};

#endif