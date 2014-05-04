#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_insert_string() {
  trie<std::string, int>* test = new trie<std::string, int>;
  
  if (not (test->insert("foo", 10) == true))
  	throw failed;
  if (not (test->insert("food", 40) == true))
  	throw failed;
  if (not (test->insert("foo", 10) == false))
  	throw failed;
  if (not (test->insert("food", 40) == false))
  	throw failed;
}

void trie_insert_charPtr() {
  trie<char*, int>* test = new trie<char*, int>;
  
  if (not (test->insert("foo", 10) == true))
    throw failed;
  if (not (test->insert("food", 40) == true))
    throw failed;
  if (not (test->insert("foo", 10) == false))
    throw failed;
  if (not (test->insert("food", 40) == false))
    throw failed;
}

int main() {
  int err = 0;
  err += test(trie_insert_string);
  err += test(trie_insert_charPtr);
  return err;
}
