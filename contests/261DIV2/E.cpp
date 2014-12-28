#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 300010;
int n,m;

struct edge {
  //int u;
  int v;
  int w;
  edge* next;
  int ind;
};

edge *g[maxn];
edge *e[maxn];

inline
int min(int a, int b) {
  return a < b ? a : b;
}

void input() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++ i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge *new_edge = (edge*)malloc (sizeof(edge));
    //new_edge->u = u;
    new_edge->v = v;
    new_edge->w = w;
    new_edge->next = g[u];
    new_edge->ind = i;
    g[u] = new_edge;
    e[i] = new_edge;
  }
}

int momo[maxn] = {-1};

inline
int max(int a, int b) {
  return a > b ? a : b;
}

int ans = 0;
inline
int dfs(int v) {
  if (momo[v] != -1) {
    return momo[v];
  }
  int longest = 0;
  edge *tmp = g[e[v]->v];
  while (tmp) {
    if (tmp->w > e[v]->w) {
      longest = max(longest, dfs(tmp->ind)+1);

    }
    tmp = tmp->next;
  }
  ans = max(ans, longest);
  return momo[v] = longest;
}

void solve() {
  memset(momo, -1, sizeof(momo));
  for (int i = 0; i < m; ++ i) {
    dfs(i);
  }
  printf("%d\n", ans+1);
}

int main() {
  input();
  solve();
  return 0;
}
