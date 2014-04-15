#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <vector>

struct trieNode {
	char id;
	int value;
	std::vector<trieNode*> neighbors;
	
	trieNode() { id = 0; value = 0;}
	trieNode(const char& letter, const int& val) {
		id = letter;
		value = val;
	}
};

struct trie {
	trieNode* head;
	trieNode* current;

	trie() {
		head = new trieNode;
		current = head;
	}

	~trie() {
		delete head;
		delete current;
	}
};

#endif