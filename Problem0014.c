#include <stdio.h>

#define limit 1000000

long collatz_sequence(long n) {
  long ret;
  if (n % 2 == 0) {
    ret = n / 2;
  }
  else {
    ret = 3 * n + 1;
  }
  //printf("%d\n", ret);
  return ret;
}

int collantz_chain(long n, int term) {
  long ret = n;
  int tmp = term;
  while (ret != 1) {
    ret = collatz_sequence(ret);
    ++tmp;
  }
  return tmp;
}

int main(int argc, char const *argv[]) {
  long i;
  int term=0;
  long max_n = 1;
  int max_term = 1;
  for (i = 1; i < limit; i++) {
    term = 1;
    term = collantz_chain(i, term);
    if (term > max_term) {
      max_term = term;
      max_n = i;
    }
  }
  printf("term=%d, n=%d\n", max_term, max_n);
  return 0;
}
