#include <stdio.h>

#define limit 2000000

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
  long sum = 0;
  int i;
  #pragma omp parallel for reduction(+:sum)
  for (i = 2; i <= limit; i++) {
    if (prime((long)i) == 1) {
      sum += i;
    }
    if (i % 100000 == 0) {
      printf("%d\n", i);
    }
  }
  printf("%ld\n", sum);
  return 0;
}
