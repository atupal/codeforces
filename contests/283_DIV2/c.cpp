#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 1100;
int n, m;
char s[maxn][maxn];
int right[maxn];
int tmp[maxn];

void solve() {
  int ans = 0;
  memset(right, 0, sizeof(maxn));
  memset(tmp, 0, sizeof(tmp));
  for (int j = 0; j < m; ++ j) {
    int flag = 0;
    for (int i = 0; i < n-1; ++ i) {
      if (! right[i]) {
        if (s[i][j] > s[i+1][j]) {
          ++ ans;
          flag = 1;
          break;
        } else if (s[i][j] < s[i+1][j]) {
          tmp[i] = 1;
        } else {
          tmp[i] = 0;
        }
      } else {
        tmp[i] = 1;
      }
    }
    if (! flag)
      memcpy(right, tmp, sizeof(tmp));
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    scanf("%s", s[i]);
  }
  solve();
  return 0;
}
