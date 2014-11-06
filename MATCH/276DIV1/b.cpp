#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 10000000;
int n;
int a[maxn];
int vis[maxn];
int b = 0;

inline
int max(int a, int b) {
  return a > b ? a : b;
}

void solve() {
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= 2*b; ++ i) {
    if (vis[i]) {
      a[i] = i;
    } else {
      a[i] = a[i-1];
    }
  }

  int ans = 0;
  for (int i = 1; i < maxn; ++ i) {
    if (vis[i])
    for (int dt = i*2; dt <= 2*b; dt += i) {
      ans = max(ans, a[dt-1]%i);
    }
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d", &n);
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a+i);
    b = max(b, a[i]);
    vis[a[i]] = 1;
  }
  solve();

  return 0;
}
