
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long int64;

const int64 maxn = 110000;

struct node {
  int64 a, b;
} nodes[maxn];

int64 cmp(node a, node b) {
  return a.b < b.b;
}

int64 n, r, arg;
int64 sum;

inline
int64 min(int64 a, int64 b) {
  return a< b ? a : b;
}

inline
int64 max(int64 a, int64 b) {
  return a > b ? a : b;
}

void solve() {
  int64 need_score = max( (int64)arg * (int64)n - sum, 0 );
  int64 ans = 0;
  for (int64 i = 0; i < n; ++ i) {
    if ( need_score > (r - nodes[i].a) ) {
      need_score -= r - nodes[i].a;
      ans += (r-nodes[i].a) * nodes[i].b;
    } else {
      ans += need_score * nodes[i].b;
      printf("%I64d\n", ans);
      return;
    }
  }
}

int main() {
  scanf("%I64d%I64d%I64d", &n, &r, &arg);
  sum = 0;
  for (int64 i = 0; i < n; ++ i) {
    scanf("%I64d %I64d", &nodes[i].a, &nodes[i].b);
    sum += (int64) nodes[i].a;
  }
  sort(nodes, nodes+n, cmp);
  solve();

  return 0;
}

