#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 110;

int n, m;
int a[maxn];
int ij[maxn][2];
int ans;

inline
int min(int a, int b) {
  return a < b ? a : b;
}

void check(int i, int j) {
  int b = min(a[i], a[j]);
  for (int x = 2; x <= b; ++ x) {
    if (a[i] % x == 0 && a[j] % x == 0) {
      while (a[i] > 1 && a[i] > 1 && a[i] % x == 0 && a[j] % x == 0) {
        ans += 1;
        a[i] /= x;
        a[j] /= x;
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < m; ++ i) {
    scanf("%d %d", ij[i], ij[i]+1);
    ij[i][0] -= 1;
    ij[i][1] -= 1;
  }
  ans = 0;
  for (int i = 0; i < m; ++ i) {
    check(ij[i][0], ij[i][1]);
  }
  printf("%d\n", ans);

  return 0;
}
