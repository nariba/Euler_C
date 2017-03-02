#include "prime.h"

#define param 100

int prime(long num) {
  if (num == 2) {
    return 1;
  }
  else if (num % 2 == 0 || num == 1) {
    return 0;
  }
  long d = num - 1;
  long s = 0;

  while (d % 2 == 0) {
    d = d / 2;
    ++s;
  }
  long i, j;
  for (i = 0; i < param; i++) {
    int isProbablyPrime = 0;
    int a = (int)(rand() % (num - 1) + 1);
    int r = modpow(a, d, num);
    if (r == 1 || r == num - 1) {
      isProbablyPrime = 1;
    }
    for (j = 0; j < s; j++) {
      r = modpow(r, 2, num);
      if (r == num - 1) {
        isProbablyPrime = 1;
      }
    }
    if (!isProbablyPrime) {
      return 0;
    }
  }
  return 1;
}

static int modpow(long x, long k, long m) {
  if (k == 0) {
    return 1;
  }
  if (k % 2 == 0) {
    return modpow(x * x % m, k / 2, m);
  }
  else {
    return (int) (modpow(x, k - 1, m) * x % m);
  }
}
