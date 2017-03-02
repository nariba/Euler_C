#include <stdio.h>

int fibonacci(int num) {
  int a=1;
  int b=1;
  int tmp;
  if (num <= 0) {
    fprintf(stderr, "invalid\n");
    return 0;
  }
  else if (num <= 1) {
    return 1;
  }
  else {
    for (int i = 0; i < num-1; i++) {
      tmp=a;
      a=a+b;
      b=tmp;
    }
    return a;
  }
}

int main(int argc, char const *argv[]) {
  int i=1;
  int sum=0;
  while (fibonacci(i)<4000000) {
    if (fibonacci(i) % 2 == 0) {
      sum += fibonacci(i);
    }
    i++;
  }
  printf("%d\n", sum);
  return 0;
}
