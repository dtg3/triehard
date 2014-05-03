#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <map>
#include <iostream>
#include <list>
#include <origin/sequence/concepts.hpp>
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
  requires Equality_comparable< Value_type<K> >()
struct trie {
  trieNode< Value_type<K>, V >* head;
  size_t val_count;
  trie(): head(new trieNode< Value_type<K>, V >) {}

  ~trie() {
    delete head;
  }

  //Add a copy constructor and move constructor
  // Copy for the nodes as well

  // look at map interface

  bool insert(const K& word, const V& val) {
    return insert(std::begin(word), std::end(word), val);
  }

  template<typename I>
    requires origin::Forward_iterator<I>()
  bool insert(I first, I last, const V& val) {
    trieNode< Value_type<K>, V >* start = buildBranches(first, last);

    if (!(start->value.empty()))
      return false;

    start->value.push_back(val);
    ++val_count;
    return true;
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

  bool erase(const K& word) {
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
    --val_count;
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

  size_t size() {
    return val_count;
  }

  bool empty() {
    return (val_count == 0);
  }

  private:
    template<typename I>
      requires origin::Forward_iterator<I>()
    trieNode< Value_type<K>, V >* buildBranches(I first, I last) {
      trieNode< Value_type<K>, V >* start = head;

      while (first != last) {
        auto search = start->neighbors.find(*first);
        
        if(search == start->neighbors.end())
          start->neighbors.insert(std::make_pair(*first, new trieNode< Value_type<K>, V >));

        start = start->neighbors[*first];
        ++first;
      }
      return start;
    }
};

#endif
