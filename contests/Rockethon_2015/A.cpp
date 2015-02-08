#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 51;

int n1, n2, k[2];
int dp[maxn][maxn][2];

int get(int n1, int n2, int type) {
  int &ret = dp[n1][n2][type];
  if (ret != -1) return ret; 

  for (int i = 1; i <= k[type]; ++ i) {
    if (n1 - i < 0) break;
    if ( !get(n2, n1-i, !type) ) {
      return ret = 1;
    }
  }

  return ret = 0;
}

void solve() {
  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < maxn; ++ i) {
    dp[i][0][0] = 1;
    dp[i][0][1] = 1;
    dp[0][i][0] = 0;
    dp[0][i][1] = 0;
  }

  if ( get(n1, n2, 0) ) {
    printf("First\n");
  } else {
    printf("Second\n");
  }

}

int main() {
  scanf("%d %d %d %d", &n1, &n2, k, k+1);
  solve();

  return 0;
}
