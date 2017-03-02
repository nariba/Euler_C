#include <stdio.h>

int prime(long num) {
  long i;
  for (i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

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
