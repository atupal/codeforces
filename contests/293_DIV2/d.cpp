#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 2001;
int n, t;
double p;
double dp[maxn][maxn];

void solve() {
  for (int i = 0; i < n; ++ i) {
    dp[0][i] = 0.;
  }
  dp[0][n] = 1.;
  for (int i = 1; i <= t; ++ i) {
    for (int j = 0; j <= n; ++ j) {
      if (j+1 <= n && j > 0) {
        dp[i][j] = dp[i-1][j+1] * p + dp[i-1][j] * (1.-p);
      } else if (j){
        dp[i][j] = dp[i-1][j] * (1.-p);
      } else {
        dp[i][j] = dp[i-1][j+1] * p + dp[i-1][j];
      }
    }
  }
  double ans = 0.;
  for (int i = 0; i <= n; ++ i) {
    ans += (double)(n-i) * dp[t][i];
  }
  printf("%lf\n", ans);
}

int main() {
  scanf("%d %lf %d", &n, &p, &t);
  solve();

  return 0;
}

