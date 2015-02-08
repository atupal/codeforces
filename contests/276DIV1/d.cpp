#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lson (root<<1)
#define rson (root<<1|1)

const int maxn = 1000100;

typedef long long int64;

inline
int64 max(int64 a, int64 b) {
  return a > b ? a : b;
}

inline
int64 min(int64 a, int64 b) {
  return a < b ? a : b;
}

static struct {
  int left;
  int right;
  int min;
  int max;
} tree[maxn*4+1];

void build(int root, int left, int right) {
  tree[root].left = left;
  tree[root].right = right;
  if (left == right) {
    scanf("%d", &tree[root].min);
    tree[root].max = tree[root].min;
    return;
  }
  int mid = (left + right) >> 1;
  build(lson, left, mid);
  build(rson, mid+1, right);
  tree[root].min = min(tree[lson].min, tree[rson].min);
  tree[root].max = max(tree[lson].max, tree[rson].max);
}

const int MIN = 1;
const int MAX = 0;
int query(int root ,int left, int right, int type) {
  if (left <= tree[root].left && tree[root].right <= right) {
    if (type == MIN)
      return tree[root].min;
    return tree[root].max;
  } else if (left > tree[root].right || right < tree[root].left) {
    if (type == MIN) 
      return (int)1e9;
    return (int)-1e9;
  }
  if (type == MIN)
    return min(query(lson, left, right, type), query(rson, left, right, type));
  return max(query(lson, left, right, type), query(rson, left, right, type));
}

typedef long long int64;
int n;
int a[maxn];
int64 dp[maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  int cnt = 0;

  for (int i = 1; i <= n; ++ i) {
    int64 pre = -1;
    double k = 1;
    int flag = 1;
    for (int j = i; j; -- j) {
      cnt += 1;
      int64 now = (int64)query(1, j, i, MAX) - (int64)query(1, j, i, MIN);
      dp[i] = max( dp[i], now + dp[j-1]);

      if (!flag && (double)(now - pre) / (double)(dp[j-1] - dp[j]) <= k) break;
      pre = now;
      k = (double)(now-pre) / (double)( dp[j-1] -dp[j] );
      flag = 0;
    }
  }
  printf("%d ", cnt);
  printf("%lld\n", dp[n]);
}

int main() {
  scanf("%d", &n);
  build(1, 1, n);
  solve();

  return 0;
}
