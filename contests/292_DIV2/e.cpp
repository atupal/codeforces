#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

#define lson root<<1
#define rson root<<1|1

typedef long long int64;
const int maxn = (int)1e5+10;
int n, m, n2;
int64 d[maxn*2];
int64 h[maxn*2];
int64 summax[maxn*2];
int64 summin[maxn*2];

static struct {
  int left;
  int right;
  int64 max;
  int64 min;
} tree[maxn*10];

inline
int64 min(int64 a, int64 b) {
  return a < b ? a : b;
}
inline
int64 max(int64 a, int64 b) {
  return a > b ? a : b;
}

void build(int root, int left, int right) {
  tree[root].left = left;
  tree[root].right = right;
  if (left == right) {
    summax[left] = d[left-1] + h[left]*2;
    summin[left] = d[left-1] - h[left]*2;
    summin[0] = max(summin[left], summin[0]);
    summax[0] = min(summax[left], summax[0]);
    tree[root].max = left;
    tree[root].min = left;
    return;
  }
  int mid = (left + right) >> 1;
  build(lson, left, mid);
  build(rson, mid+1, right);
  if ( summax[tree[lson].max] > summax[tree[rson].max]) {
    tree[root].max = tree[lson].max;
  } else {
    tree[root].max = tree[rson].max;
  }
  if ( summin[tree[lson].min] < summin[tree[rson].min]) {
    tree[root].min = tree[lson].min;
  } else {
    tree[root].min = tree[rson].min;
  }
}

int query_max(int root, int left, int right) {
  if ( left <= tree[root].left && tree[root].right <= right ) {
    return tree[root].max;
  } else if (tree[root].left > right || tree[root].right < left) {
    return 0;
  }
  int l = query_max(lson, left, right);
  int r = query_max(rson, left, right);
  if ( summax[l] > summax[r] ) {
    return l;
  } else {
    return r;
  }
}

int query_min(int root, int left, int right) {
  if ( left <= tree[root].left && tree[root].right <= right ) {
    return tree[root].min;
  } else if (tree[root].left > right || tree[root].right < left) {
    return 0;
  }
  int l = query_min(lson, left, right);
  int r = query_min(rson, left, right);
  if ( summin[l] < summin[r] ) {
    return l;
  } else {
    return r;
  }
}

void solve() {
  build(1, 1, n2);
  //summax[0] = 0;
  // summin[0] = 1L<<61;  // CF win32 BUG!
  int l, r, left, right;
  for (int i = 0; i < m; ++ i) {
    cin >> l >> r;
    if (l <= r) {
      l += n;
    }
    left = r+1;
    right = l-1;

    int64 ret = 0;
    int R = query_max(1, left, right);
    int L = query_min(1, left, right);
    if (L != R) {
      cout << summax[R] - summin[L] << endl;
    } else {
      if (left <= L-1) ret = max(ret, summax[L] - summin[ query_min(1, left, L-1) ]);
      if (L+1 <= right) ret = max(ret, summax[ query_max(1, L+1, right) ] - summin[L]);
      cout << ret << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  n2 = n<<1;
  d[0] = 0;
  for (int i = 1; i <= n; ++ i) {
    cin >> d[i];
    d[i] += d[i-1];
  }
  for (int i = n+1; i <= n2; ++ i) {
    d[i] = d[n] + d[i-n];
  }
  for (int i = 1; i <= n; ++ i) {
    cin >> h[i];
    h[n+i] = h[i];
  }
  solve();

  return 0;
}

