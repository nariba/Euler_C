#include <stdio.h>

int is_divided_num(int num, int limit) {
  int i;
  for (i = 1; i <= limit; i++) {
    if (num % i != 0) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int i=1;
  while (is_divided_num(i, 20) == 0) {
    i++;
  }
  printf("%d\n", i);
  return 0;
}
