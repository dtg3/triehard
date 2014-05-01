#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_count() {
  trie<std::string, int>* test = new trie<std::string, int>;
  test->insert("foo", 10);
  
  if (not (test->count("foo") == 1))
    throw failed;
  if (not (test->count("food") == 0))
    throw failed;
  
  test->insert("food", 10);
  if (not (test->count("food") == 1))
    throw failed;
}

int main() {
  int err = 0;
  err += test(trie_count);
  return err;
}
