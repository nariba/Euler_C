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
  long i=sqrt(n);
  while (1) {
    if (n % i == 0 && prime(i) == 1) {
      printf("%ld\n", i);
      break;
    }
    --i;
  }
  return 0;
}
