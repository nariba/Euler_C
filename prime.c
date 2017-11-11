#include "prime.h"

int imod(long int a, long int n) {
  int r;
  r = (a + n) % n;
  if(r < 0) r += n;
  return r;
}

int pow_mod(long int a, long int e, long int n) {
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
    else if (n < 200) {
        if (n == 3 || n == 5 || n == 7 || n == 11
            || n == 13 || n == 17 || n == 19 || n == 23 || n == 29
            || n == 31 || n == 37 || n == 41 || n == 43 || n == 47
            || n == 53 || n == 59 || n == 61 || n == 67 || n == 71
            || n == 73 || n == 79 || n == 83 || n == 89 || n == 97
            || n == 101 || n == 103 || n == 107 || n == 109 || n == 113
            || n == 127 || n == 131 || n == 137 || n == 139 || n == 149
            || n == 151 || n == 157 || n == 163 || n == 167 || n == 173
            || n == 179 || n == 181 || n == 191 || n == 193 || n == 197
            || n == 199) {
            ret = true;
        }
        else {
            ret = false;
        }
    }
    else {
        long int d = n - 1;
        int s = 0;
        while (d % 2 == 0) {
            d = d / 2;
            s++;
        }
        for (int i = 0; i < k; i++) {
            bool isPP = false;
            // 1からn-1の範囲から整数aをランダムに選ぶ
            long int a = random() % (n - 2) + 1;
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
