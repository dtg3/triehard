#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <map>
#include <iostream>
#include <list>

//LATER...
//TRINODE BASE and TRINODE

// Template Params:
// K, Key V, Value
template<typename K, typename V>
struct trieNode {
  std::list<V> value;
  std::map<K, trieNode<K, V>* > neighbors;
  
  trieNode(): value(), neighbors() {}
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

  //Add a copy constructor and move constructor
  // Copy for the nodes as well

  // Forward Iterators for input
  // Read input for trie insertion that takes a range of iterators (first and last)

  // split up insert and branch creation

  bool insert(const K& word, const V& val) {
    trieNode< Value_type<K>, V >* start = head;
    bool exists = true;

    for (std::size_t i = 0; word[i] != '\0'; ++i) {
      auto search = start->neighbors.find(word[i]);
      
      if(search == start->neighbors.end()) {
        start->neighbors.insert(std::make_pair(word[i], new trieNode< Value_type<K>, V >));
        exists = false;
      }
      
      start = start->neighbors[word[i]];
    }

    if (!exists)
     start->value.push_back(val); 

    return !exists;
  }
  
  void remove(const K& word) {}
  
  size_t count(const K& word) {
    trieNode< Value_type<K>, V >* start = head;
    for (std::size_t i = 0; word[i] != '\0'; ++i) {
      
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
