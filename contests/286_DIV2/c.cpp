#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 30001;

int sum[maxn];
int cnt[maxn];

int max;
void dfs(int pos, int l, int ans) {
  if (pos>=maxn) return;
  ans += cnt[pos];
  if (ans >= max) {
    max = ans;
  }
  if (l==1) {
    ans += sum[maxn-1]-sum[pos];
    if (ans > max) {
      max = ans;
    }
    return;
  }

  if ( ans+sum[maxn-1]-sum[pos+l-1] <= max) {
    return;
  }

  if (l-1) {
    dfs(pos+l, l-1, ans);
  }
  dfs(pos+l, l, ans);
  dfs(pos+l, l+1, ans);
}

int main() {
  memset(sum, 0, sizeof(sum));
  memset(cnt, 0, sizeof(cnt));
  int n, d;
  scanf("%d %d", &n, &d);
  while (n--) {
    int p;
    scanf("%d", &p);
    ++ cnt[p];
  }
  for (int i = 1; i < maxn; ++ i) {
    sum[i] = sum[i-1] + cnt[i];
  }
  max = 0;
  dfs(0, d, 0);
  printf("%d\n", max);

  return 0;
}
