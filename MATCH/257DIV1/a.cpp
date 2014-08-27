#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, k;

inline
int f(int x) {
  return ((n/(x+1))*(m/(k-x+1)));
}

inline
int max(int a, int b ) {
  return a > b ? a : b;
}

inline
int min(int a, int b ) {
  return a < b ? a : b;
}

void solve() {
  int ans = 0;
  ans = f(min(k, n-1));
  ans = max(ans, f(k-min(k, m-1)));
  ans = max(ans, f(min(k-1, n-1)));
  ans = max(ans, f(k-min(k-1, m-1)));
  printf("%d\n", ans ? ans : -1);
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  solve();
  return 0;
}
