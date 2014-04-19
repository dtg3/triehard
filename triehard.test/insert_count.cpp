#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_insert_count() {
  trie<std::string, int>* test = new trie<std::string, int>;
  test->add("foo", 10);
  if (not (test->count("foo") == 1))
    throw failed;

  if (not (test->count("food") == 0))
    throw failed;
}

int main() {
  int err = 0;
  err += test(trie_insert_count);
  return err;
}