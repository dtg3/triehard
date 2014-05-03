#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_size() {
  trie<std::string, int>* test = new trie<std::string, int>;
  if (not (test->size() == 0))
    throw failed;

  test->insert("foo", 10);
  if (not (test->size() == 1))
  	throw failed;
  
  test->insert("food", 40);
  if (not (test->size() == 2))
    throw failed;

  test->erase("foo");
  if (not (test->size() == 1))
    throw failed;

  test->erase("food");
  if (not (test->size() == 0))
    throw failed;
}

int main() {
  int err = 0;
  err += test(trie_size);
  return err;
}
