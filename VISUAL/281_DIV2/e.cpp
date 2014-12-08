#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int64;

const int MOD = (int)1e9+7;

int64 t, a, b;

void solve() {
  if (t==1) {
    if (a == 1) {
      if (b == 1) {
        printf("inf\n");
      } else {
        printf("0\n");
      }
      return;
    }

    int64 tmp = b;
    while (tmp) {
      if (tmp%a) {
        break;
      }
      tmp /= a;
    }
    if (tmp==1 && b>=a) {
      printf("1\n");
      return;
    }
  }

  int r = 0;
  if (a == b) r = 1;

  int cnt = 0;
  int64 ret = 0;
  while (a != 1 && b) {
    int64 tmp = b%a;
    for (int i = 0; i < cnt; ++ i) {
      tmp *= t;
    }
    ret += tmp;
    if (ret > a) {
      break;
    }
    b /= a;
    cnt += 1;
  }
  if (a == ret) {
    r += 1;
  }
  printf("%d\n", r);
}

int main() {
  scanf("%I64d %I64d %I64d", &t, &a, &b);
  solve();

  return 0;
}
