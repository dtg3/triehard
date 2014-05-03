#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_insert() {
  trie<std::string, int>* test = new trie<std::string, int>;
  
  if (not (test->insert("food", 40) == true))
    throw failed;
  if (not (test->remove("food") == true))
    throw failed;
  if (not (test->remove("food") == false))
    throw failed;
}

int main() {
  int err = 0;
  err += test(trie_insert);
  return err;
}
