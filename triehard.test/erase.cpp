#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void trie_erase() {
  trie<std::string, int>* test = new trie<std::string, int>;
  
  if (not (test->insert("food", 40) == true))
    throw failed;
  if (not (test->erase("food") == true))
    throw failed;
  if (not (test->erase("food") == false))
    throw failed;
}

int main() {
  int err = 0;
  err += test(trie_erase);
  return err;
}
