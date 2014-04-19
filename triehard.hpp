#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <map>
#include <iostream>

//LATER...
//TRINODE BASE and TRINODE

// Template Params:
// K, Key V, Value
template<typename K, typename V>
struct trieNode {
  V* value;
  std::map<K, trieNode<K, V>* > neighbors;
  
  trieNode(): value(NULL), neighbors() {}
  trieNode(const V& val) : value(val) {}

  ~trieNode() {
    delete value;
  }
};

template<typename K, typename V>
struct trie {
  trieNode< Value_type<K>, V >* head;

  trie(): head(new trieNode< Value_type<K>, V >) {}

  ~trie() {
    delete head;
  }

  bool add(const K& word, const V& val) {
    trieNode< Value_type<K>, V >* start = head;
    bool exists = true;

    for (std::size_t i = 0; i < word.length(); ++i) {
      auto search = start->neighbors.find(word[i]);
      
      if(search == start->neighbors.end()) {
        start->neighbors.insert(std::make_pair(word[i], new trieNode< Value_type<K>, V >));
        exists = false;
      }
      
      start = start->neighbors[word[i]];
    }

    if (!exists)
     start->value = new V(val); 

    return !exists;
  }
  
  void remove(const K& word) {}
  
  size_t count(const K& word) {
    trieNode< Value_type<K>, V >* start = head;
    for (std::size_t i = 0; i < word.length(); ++i) {
      
      auto search = start->neighbors.find(word[i]);
      if(search == start->neighbors.end())
        return 0;
      
      start = start->neighbors[word[i]];
    }
    return 1;
  }

  int* operator[] (const K& word) {
    return head->value;
  }
};

#endif
