#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define start 100
#define end 1000

int is_palindromic(int num) {
  char str[100];
  sprintf(str, "%d", num);
  int len = strlen(str);

  char *c_num;
  c_num = malloc(sizeof(char) * len);
  int i, count;
  if (len % 2 == 0) {
    count = len/2;
  }
  else {
    count = len/2+1;
  }
  for (i = 0; i < count; i++) {
    if (str[i] != str[len-(i+1)]) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int max = 0;
  int i, j;
  for (i = start; i < end; i++) {
    for (j = start; j < end; j++) {
      if (is_palindromic(i*j) == 1 && i*j > max) {
        max = i*j;
      }
    }
  }
  printf("%d\n", max);
  return 0;
}
