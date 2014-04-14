#include "triehard.hpp"
#include "test.hpp"
#include <iostream>

void test_simple() {
  if (not (test_add_five(4)) == 9)
    throw failed;
}

int main() {
	int err = 0;
	err += test(test_simple);
	return err;
}