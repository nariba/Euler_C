#include <stdio.h>

#define limit 1000

int main(int argc, char const *argv[]) {
  int i, sum=0;
  for (i = 1; i < limit; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  printf("sum=%d\n", sum);
  return 0;
}
