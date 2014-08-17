#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long  n,k,d;

int ans[1000][1000];

void put(int ind) {
  for (int i = 0; i < d; ++ i) {
    ans[i][ind] = ans[i][ind-1];
  }
  int y = d-1;
  while (1 and y >= 0) {
    if (ans[y][ind]+1 >= k) {
      ans[y][ind] = 0;
      y -= 1;
    } else {
      ++ ans[y][ind];
      break;
    }
  }
}

void solve() {
  scanf("%I64d %I64d %I64d", &n, &k, &d);
  int tmp = 1;
  do {
    for (int i = 0; i < d; ++ i) {
      tmp *= k;
      if (tmp >= n) {
        goto tag2;
      }
    }
    printf("-1\n");
    exit(0);
  } while (0);
tag2:
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i < n; ++ i) {
    put(i);
  }
  for (int i = 0; i < d; ++ i) {
    for (int j = 0; j < n; ++ j) {
      printf("%d ", ans[i][j]+1);
    }
    printf("\n");
  }
}

int main () {
  solve();
  return 0;
}
