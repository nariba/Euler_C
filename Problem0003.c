#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define n 600851475143

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
  long n=atol(argv[1]);
  long i = n / 2;
  i = 2;
  while (n >= i) {
    if (prime(i) && n % i == 0) {
      n = n / i;
    }
    else {
      ++i;
    }
    if (i % 10000000 == 0)
      printf("%ld\n", i);
  }
  printf("%ld\n", i);
  return 0;
}
