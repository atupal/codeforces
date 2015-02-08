#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 100000;

int n, t;
int a[maxn];
int dp[maxn];

int main() {
  scanf("%d %d", &n, &t);
  for (int i = 1; i < n; ++ i) {
    scanf("%d", a+i);
  }

  memset(dp, 0, sizeof(dp));
  dp[1] = 1;
  for (int i = 1; i < n; ++ i) {
    if (!dp[i+a[i]] && dp[i]) {
      dp[i+a[i]] = 1;
    }
  }

  if (dp[t]) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}
