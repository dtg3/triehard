#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <map>
#include <iostream>

struct trieNode {
	int value;
	std::map<char, trieNode*> neighbors;
	
	trieNode() { value = 0; }
	trieNode(const int& val) {
		value = val;
	}
};

struct trie {
	trieNode* head;

	trie() {
		head = new trieNode;
	}

	~trie() {
		delete head;
	}

	void add(const std::string word, const int& val) {
		trieNode* start = head;
		for (unsigned int i = 0; i < word.length(); ++i) {
			std::map<char,trieNode*>::const_iterator search = start->neighbors.find(word[i]);
    		
    		if(search == start->neighbors.end()) {
    			start->neighbors[word[i]] = new trieNode(0);
    		}
    		
    		start = start->neighbors[word[i]];
		}
	}
	
	void remove(const std::string word) {}
	
	bool find(const std::string word) {
		trieNode* start = head;
		for (unsigned int i = 0; i < word.length(); ++i) {
			std::map<char,trieNode*>::const_iterator search = start->neighbors.find(word[i]);
    		if(search == start->neighbors.end())
    			return false;
    		
    		start = start->neighbors[word[i]];
		}
		return true;
	}

	int& operator[] (const std::string word) {
		return head->value;
	}
};

#endif