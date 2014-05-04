#ifndef TRIEHARD_HPP
#define TRIEHARD_HPP

#include "concepts.hpp"
#include <string>
#include <string.h>
#include <map>
#include <iostream>
#include <list>
#include <origin/sequence/concepts.hpp>

//LATER...
//TRINODE BASE and TRINODE
//Add a copy constructor and move constructor
//Copy for the nodes as well
//Look at map interface

/*
  trieNode
  Storage node utilized in trie structure
*/
template<typename K, typename V>
struct trieNode {
  std::list<V> value;
  std::map<K, trieNode<K, V>* > neighbors;
};

/*
  trie
  trie structure for mapping keys to values
  current support is for string and char based keys
*/
template<typename K, typename V>
  requires Equality_comparable< Value_type<K> >()
struct trie {
  // Root trie node
  trieNode< Value_type<K>, V >* head;
  
  // Count of values contained within trie
  size_t val_count;

  trie(): head(new trieNode< Value_type<K>, V >) {}

  ~trie() {
    delete head;
  }

  /*
    INSERT FUNCTIONS
  */
  // Add string based key value pair to trie
  bool insert(const std::string& word, const V& val) {
    return insert(std::begin(word), std::end(word), val);
  }

  // Add char* based key value pair to trie
  bool insert(const char* word, const V& val) {
    return insert(&word[0], &word[strlen(word)], val);
  }

  // Add key value part to trie via iterators
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

  /*
    FETCH FUNCTIONS
  */
  // Fetch value based on string key in trie
  V* fetch(const std::string& word) {
    return fetch(std::begin(word), std::end(word));
  }

  // Fetch value based on char* key in trie
  V* fetch(const char* word) {
    return fetch(&word[0], &word[strlen(word)]);
  }

  // Retrieval of values from trie based on key
  //   Used in place of [] operator due to time constraints
  template<typename I>
    requires origin::Forward_iterator<I>()
  V* fetch(I first, I last) {
    trieNode< Value_type<K>, V >* start = findNode(first, last);
    if(start != NULL && !(start->value.empty()))
      return &(start->value.front());
    else
      return NULL;
  }

  /*
    ERASE FUNCTIONS
  */
  // Erase value based on string key in trie
  bool erase(const std::string& word) {
    return erase(std::begin(word), std::end(word));
  }

  // Erase value based on char* key in trie
  bool erase(const char* word) {
    return erase(&word[0], &word[strlen(word)]);
  }

  // Remove value from trie
  template<typename I>
    requires origin::Forward_iterator<I>()
  bool erase(I first, I last) {
    trieNode< Value_type<K>, V >* start = findNode(first, last);
    if (start == NULL || start->value.empty())
      return false;
    
    start->value.clear();
    --val_count;
    return true;
  }

  /*
    COUNT FUNCTIONS
  */
  // Find string based key in trie
  size_t count(const std::string& word) {
    return count(std::begin(word), std::end(word));
  }

  // Find char* based key in trie
  size_t count(const char* word) {
    return count(&word[0], &word[strlen(word)]);
  }
  
  // Determine if key is associated with a value
  template<typename I>
    requires origin::Forward_iterator<I>()
  size_t count(I first, I last) {
    trieNode< Value_type<K>, V >* start = findNode(first, last);
    return (start != NULL && !(start->value.empty()));
  }

  // Return number of values in trie
  size_t size() {
    return val_count;
  }

  // Return whether trie contains values or is empty
  bool empty() {
    return (val_count == 0);
  }

  // Helper functions
  private:
    // Builds the branches necessary for an insert into the trie
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

    // Determines if a node exists along a path given two iterators
    template<typename I>
      requires origin::Forward_iterator<I>()
    trieNode< Value_type<K>, V >* findNode(I first, I last) {
      trieNode< Value_type<K>, V >* start = head;

      while (first != last) {
        auto search = start->neighbors.find(*first);
        
        if(search == start->neighbors.end())
          return NULL;

        start = start->neighbors[*first];
        ++first;
      }
      return start;
    }
};

#endif
