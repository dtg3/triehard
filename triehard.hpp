#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <map>
#include <iostream>
#include <list>
#include <iostream> // FOR TESTING ONLY

//LATER...
//TRINODE BASE and TRINODE

// Template Params:
// K, Key V, Value
template<typename K, typename V>
struct trieNode {
  std::list<V> value;
  std::map<K, trieNode<K, V>* > neighbors;
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

  // look at map interface

  bool insert(const K& word, const V& val) {
    trieNode< Value_type<K>, V >* start = buildBranches(word);

    if (!(start->value.empty()))
      return false;

    start->value.push_back(val); 
    return true;
  }
  
  bool remove(const K& word) {
    trieNode< Value_type<K>, V >* start = head;
    for (std::size_t i = 0; word[i] != '\0'; ++i) {
      
      auto search = start->neighbors.find(word[i]);
      if(search == start->neighbors.end())
        return false;
      
      start = start->neighbors[word[i]];
    }

    if (start->value.empty())
      return false;
    
    start->value.clear();
    return true;
  }
  
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

  V* fetch(const K& word) {
    trieNode< Value_type<K>, V >* start = head;
    for (std::size_t i = 0; word[i] != '\0'; ++i) {
      
      auto search = start->neighbors.find(word[i]);
      if(search == start->neighbors.end())
        return NULL;
      
      start = start->neighbors[word[i]];
    }

    return &(start->value.front());
  }

  private:
    trieNode< Value_type<K>, V >* buildBranches(const K& word) {
      trieNode< Value_type<K>, V >* start = head;

      for (std::size_t i = 0; word[i] != '\0'; ++i) {
        auto search = start->neighbors.find(word[i]);
        
        if(search == start->neighbors.end())
          start->neighbors.insert(std::make_pair(word[i], new trieNode< Value_type<K>, V >));

        start = start->neighbors[word[i]];
      }

      return start;
    }
};

#endif
