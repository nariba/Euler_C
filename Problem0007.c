#include <stdio.h>
#include "mylib/prime.h"

int main(int argc, char const *argv[]) {
  int num=0;
  int i=1;
  while (num < 10001) {
    ++i;
    if (prime((long)i) == 1) {
      ++num;
    }
  }
  printf("%d\n", i);
  return 0;
}
