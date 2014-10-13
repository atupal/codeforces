#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 2010;
char s[maxn], p[maxn];

int dp[maxn][maxn];

inline
int max(int a, int b) {
  return a > b ? a : b;
}

void solve() {
  memset(dp, 0, sizeof(dp));
  int ls = (int) strlen(s);
  int lp = (int) strlen(p);
  dp[0][0] = 0;

  static struct {
    int pos;
    int cnt;
  } jump[maxn];

  for (int i = 1; i <= ls; ++ i) {
    int p1 = i-1, p2 = lp - 1;
    int cnt = 0;
    while (p1 >= 0 and p2 >= 0) {
      if (s[p1] == p[p2]) {
        -- p2;
      } else {
        ++ cnt;
      }
      -- p1;
    }
    if (p2 == -1) {
      jump[i].pos = p1;
      jump[i].cnt = cnt;
    } else {
      jump[i].pos = -2;
    }
  }

  for (int i = 1; i <= ls; ++ i) {
    for (int j = 0; j <= i; ++ j) {
      dp[i][j] = dp[i-1][j];
      if (jump[i].pos != -2 and j - jump[i].cnt >= 0 and jump[i].pos+1>=j-jump[i].cnt) {
        dp[i][j] = max(dp[i][j], dp[jump[i].pos+1][j-jump[i].cnt] + 1);
      }
    }
  }
  for (int i = 0; i <= ls; ++ i) {
    printf("%d ", dp[ls][i]);
  }
}

int main() {
  scanf("%s %s", s, p);
  solve();
  return 0;
}
