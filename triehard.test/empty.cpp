#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_empty() {
  trie<std::string, int>* test = new trie<std::string, int>;
  if (not (test->empty() == true))
    throw failed;

  test->insert("foo", 10);
  if (not (test->empty() == false))
  	throw failed;

  test->remove("foo");
  if (not (test->empty() == true))
    throw failed;
}

int main() {
  int err = 0;
  err += test(trie_empty);
  return err;
}
