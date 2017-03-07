#include <stdio.h>

int sum_seq(int num) {
  int sum = 0;
  int i;
  for (i = 1; i <= num; i++) {
    sum += i*i;
  }
  return sum;
}

int seq_sum(int num) {
  int sum = 0;
  int i;
  for (i = 1; i <= num; i++) {
    sum += i;
  }
  sum = sum*sum;
  return sum;
}

int main(int argc, char const *argv[]) {
  int i=100;
  printf("%d\n", seq_sum(i)-sum_seq(i));
  return 0;
}
