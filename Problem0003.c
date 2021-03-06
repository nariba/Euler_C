#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int imod(int a, int n)
{
  int r;
  r = (a + n) % n;
  if(r < 0) r += n;
  return r;
}

int pow_mod(int a, int e, int n)
{
  int r = 1;
  a = imod(a, n);
  while(e > 0){
    if ((e & 1) == 1) r = imod(r*a, n);
    e >>= 1;
    a = imod(a*a, n);
  }
  return r;
}

bool is_prime(long int n, int k) {
    bool ret = true;

    if (n == 2) {
        ret = true;
    }
    else if (n <= 1 || n % 2 == 0 ) {
        ret = false;
    }
    else {
        int d = n - 1;
        int s = 0;
        while (d % 2 == 0) {
            d = d / 2;
            s++;
        }
        for (int i = 0; i < k; i++) {
            bool isPP = false;
            // 1からn-1の範囲から整数aをランダムに選ぶ
            int a = random() % (n - 2) + 1;
            // if(a^d mod n == (1 or n-1), then n is probably prime
            int r = pow_mod(a, d, n);
            if (r == 1 || r == n - 1) {
                isPP = true;
            }
            // if(r^2 mod n == -1), then n is probably prime
            for (int j = 0; j < s; j++) {
                r = pow_mod(r, 2, n);
                if (r == n - 1) {
                    isPP = true;
                }
            }

            if (!isPP) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }
    long int num = atol(argv[1]);
    long int max = 1;

    for(long int i = 1; i <= num; i++) {
        if (is_prime(i, 1000) && num % i == 0) {
            max = i;
            num = num / i;
        }
    }
    printf("max=%ld\n", max);
    return 0;
}
