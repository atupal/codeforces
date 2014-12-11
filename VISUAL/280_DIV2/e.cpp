#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = (int)1e6+10;

int n, m, dx, dy;
int ans[maxn];
int r[maxn];

inline
int abs(int x) {
  if (x < 0) return -x; 
  return x;
}

void solve() {
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n; ++ i) {
    r[(long long) i * (long long) dx %(long long)n] = i;
  }
  r[n] = r[0];
  for (int i = 0; i < m; ++ i) {
    int x, y;
    scanf("%d %d", &x, &y);
    ans[ ((long long) y + (long long)r[n-x] * (long long)dy) % (long long )n ] += 1;
  }
  int max = 0;
  int out = 0;
  for (int i = 0; i < n; ++ i) {
    if (ans[i] > max) {
      max = ans[i];
      out = i;
    }
  }
  printf("%d %d\n", 0, out);
}

int main() {
  scanf("%d %d %d %d", &n, &m, &dx, &dy);
  solve();

  return 0;
}
