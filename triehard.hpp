#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <map>
#include <iostream>

// Template Params:
// K, Key V, Value
template<typename K, typename V>
struct trieNode {
	V* value;
	std::map<K, trieNode<K, V>* > neighbors;
	
	trieNode() { value = NULL; }
	trieNode(const V& val) {
		value = val;
	}

	~trieNode() {
		delete value;
	}

	V* getValue() {
		return value;
	}
};

struct trie {
	trieNode<char, int>* head;

	trie() {
		head = new trieNode<char, int>;
	}

	~trie() {
		delete head;
	}

	void add(const std::string word, const int& val) {
		trieNode<char, int>* start = head;
		for (unsigned int i = 0; i < word.length(); ++i) {
			std::map< char,trieNode<char, int>* >::const_iterator search = start->neighbors.find(word[i]);
    		
    		if(search == start->neighbors.end()) {
    			start->neighbors[word[i]] = new trieNode<char, int>;
    		}
    		
    		start = start->neighbors[word[i]];
		}
	}
	
	void remove(const std::string word) {}
	
	bool find(const std::string word) {
		trieNode<char, int>* start = head;
		for (unsigned int i = 0; i < word.length(); ++i) {
			std::map< char,trieNode<char, int>* >::const_iterator search = start->neighbors.find(word[i]);
    		if(search == start->neighbors.end())
    			return false;
    		
    		start = start->neighbors[word[i]];
		}
		return true;
	}

	int* operator[] (const std::string word) {
		return head->getValue();
	}
};

#endif
