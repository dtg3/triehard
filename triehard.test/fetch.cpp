#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_fetch() {
  trie<std::string, int>* test = new trie<std::string, int>;
  test->insert("foo", 10);
  std::cerr << *test->fetch("foo");

  if (not (*(test->fetch("foo")) == 10))
    throw failed;
  if (not (test->fetch("food") == NULL))
    throw failed;

  test->insert("food", 20);
  if (not (*(test->fetch("foo")) == 10))
    throw failed;
  if (not (*(test->fetch("food")) == 20))
    throw failed;  
  if (not (test->fetch("foot") == NULL))
    throw failed;  
}

int main() {
  int err = 0;
  err += test(trie_fetch);
  return err;
}
