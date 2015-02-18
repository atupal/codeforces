#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 110;
int n, m;
int a, b;
int x[maxn];
int y[maxn];

int gcd(int a, int b) {
  if (a < b) a^=b^=a^=b;
  return b==0? a : gcd(b, a%b);
}

int main() {
  scanf("%d %d", &n, &m);
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  scanf("%d", &a);
  for (int i = 0; i < a; ++ i) {
    scanf("%d", &b);
    x[b] = 1;
  }
  scanf("%d", &b);
  for (int i = 0; i < b; ++ i) {
    scanf("%d", &a);
    y[a] = 1;
  }
  int g = gcd(n, m);
  for (int l = 0; l < g; ++ l) {
    int flag = 0;
    for (int i = l; i < n; i += g) {
      if (x[i]) {
        flag = 1;
      }
    }
    for (int i = l; i < m; i += g) {
      if (y[i]) {
        flag = 1;
      }
    }
    if (!flag) {
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");

  return 0;
}

