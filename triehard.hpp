#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <map>

struct trieNode {
	char id;
	int value;
	std::map<char, trieNode*> neighbors;
	
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

	void add(const std::string word, const int& val) {}
	
	void remove(const std::string word) {}
	
	bool find(const std::string word) {
		return true;
	}

	int& operator[] (const std::string word) {
		return current->value;
	}
};

#endif