#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline
int min(int a, int b) {
  return a < b ? a : b;
}

inline
int max(int a, int b) {
  return a > b ? a : b;
}

int x1, y1, x2, y2;
int a, b, c;
int get() {
  double z1 = (double)a*(double)x1 + (double)b*(double)y1 + (double)c;
  double z2 = (double)a*(double)x2 + (double)b*(double)y2 + (double)c;
  return z1*z2 < 0;
}

int main() {
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; ++ i) {
    scanf("%d %d %d", &a, &b, &c);
    ans += get();
  }
  printf("%d\n", ans);

  return 0;
}
