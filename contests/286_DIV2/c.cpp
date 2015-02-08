#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>


const int maxn = 30001;

int sum[maxn];
int cnt[maxn];
std::vector<std::pair<int, int> > dp[maxn];

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
  //dfs(0, d, 0);
  // no dfs, use iter!
  dp[d].push_back(std::make_pair(d, cnt[d]));

  for (int i = d; i < maxn; ++ i) {
    int size = dp[i].size();
    std::sort(dp[i].begin(), dp[i].end());
    for (int j = size-1; j>=0; -- j) {
      if ( j<size-1 && dp[i][j+1].first == dp[i][j].first ) {
        continue;
      }
      int l = dp[i][j].first;
      int s = dp[i][j].second;
      if (s>max) {
        max=s;
      }
      if (l-1 && i+l-1<maxn) {
        dp[i+l-1].push_back(std::make_pair(l-1, s+cnt[i+l-1]));
      }
      if (l&&i+l<maxn) {
        dp[i+l].push_back(std::make_pair(l, s+cnt[i+l]));
      }
      if (i+l+1<maxn) {
        dp[i+l+1].push_back(std::make_pair(l+1, s+cnt[i+l+1]));
      }
    }
  }

  printf("%d\n", max);

  return 0;
}

