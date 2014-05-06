#include "triehard.hpp"
#include "test.hpp"
#include <iostream>
#include <vector>

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

void trie_insert_vecInt() {
  std::vector<int> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  std::vector<int> data2;
  data2.push_back(1);
  data2.push_back(2);

  trie<std::vector<int>, int>* test2 = new trie<std::vector<int>, int>;
  test2->insert(std::begin(data), std::end(data), 5);
  test2->insert(std::begin(data2), std::end(data2), 7);

  if (not (*test2->fetch(std::begin(data), std::end(data)) == 5))
    throw failed;
}

int main() {
  int err = 0;
  err += test(trie_insert_string);
  err += test(trie_insert_charPtr);
  return err;
}
