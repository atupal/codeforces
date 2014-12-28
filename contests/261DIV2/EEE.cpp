#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 300010;
int n,m;

struct edge {
  int u;
  int v;
  int w;
};

edge e[maxn];

int cpm(edge a, edge b) {
  return a.w < b.w;
}

inline
int max(int a, int b) {
  return a > b ? a : b;
}

void input() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++ i) {
    scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
  }
}

int dp1[maxn];
int dp2[maxn];


int ans = 0;
void solve() {
  memset(dp2, 0, sizeof(dp2));
  memset(dp1, 0, sizeof(dp1));
  sort(e, e+m, cpm);
  dp2[e[0].v] = 1;
  vector <int> vec;
  vec.push_back(e[0].v);
  for (int i = 1; i < m; ++ i) {
    if (e[i].w > e[i-1].w) {
      int size = vec.size();
      for (int x = 0; x < size; ++ x) {
        dp1[vec[x]] = dp2[vec[x]];
      }
      vec.clear();
    }
    dp2[e[i].v] = max(dp2[e[i].v], dp1[e[i].u] + 1);
    ans = max(ans, dp2[e[i].v]);
    vec.push_back(e[i].v);
  }
  printf("%d\n", ans);
}

int main() {
  input();
  solve();
  return 0;
}
