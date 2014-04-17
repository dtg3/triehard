#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <map>
#include <iostream>

//LATER...
//TRINODE BASE and TRINODE

// USE IT: LOOKUP MEMBER INITIALIZER LIST
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
};

//MAKE TEMPLATE
struct trie {
  // GET VALUE TYPE OF STRING which is Char
  // NEEDS TO BE A VALUE TYPE
  trieNode<char, int>* head;

  trie() {
    head = new trieNode<char, int>;
  }

  ~trie() {
    delete head;
  }

  bool add(const std::string& word, const int& val) {
    trieNode<char, int>* start = head;
    bool exists = true;

    for (std::size_t i = 0; i < word.length(); ++i) {
      auto search = start->neighbors.find(word[i]);
      
      if(search == start->neighbors.end()) {
        // USE INSERT INSTEAD
        start->neighbors[word[i]] = new trieNode<char, int>;
        exists = false;
      }
      
      start = start->neighbors[word[i]];
    }

    return !exists;
  }
  
  void remove(const std::string& word) {}
  
  size_t count(const std::string& word) {
    trieNode<char, int>* start = head;
    for (std::size_t i = 0; i < word.length(); ++i) {
      
      auto search = start->neighbors.find(word[i]);
      if(search == start->neighbors.end())
        return 0;
      
      start = start->neighbors[word[i]];
    }
    return 1;
  }

  int* operator[] (const std::string word) {
    return head->value;
  }
};

#endif
