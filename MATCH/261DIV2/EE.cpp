#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 300100;
int n,m;

struct edge {
  //int u;
  int v;
  int w;
  edge* next;
  int ind;
};

edge *g[maxn];
edge e[maxn];
edge ee[maxn];

inline
int min(int a, int b) {
  return a < b ? a : b;
}

void input() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++ i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    //edge *new_edge = (edge*)malloc (sizeof(edge));
    edge *new_edge = e+i;

    //new_edge->u = u;
    new_edge->v = v;
    new_edge->w = w;
    new_edge->next = g[u];
    new_edge->ind = i;
    g[u] = new_edge;
    //e[i] = *new_edge;
  }
}

inline
int max(int a, int b) {
  return a > b ? a : b;
}

int cmp(edge a, edge b) {
  return (a.w) < (b.w);
}

int momo[maxn];
int ans = 0;
void solve() {
  memset(momo, 0, sizeof(momo));
  memcpy(ee, e, sizeof(e));
  sort(ee, ee+m, cmp);
  for (int i = 0; i < m; ++ i) {
    edge *tmp = g[ee[i].v];
    while (tmp) {
      if (tmp->w > ee[i].w) {
        momo[tmp->ind] = max(momo[tmp->ind], momo[ee[i].ind]+1);
        ans = max(ans, momo[tmp->ind]);
      }
      tmp = tmp->next;
    }
  }
  printf("%d\n", ans+1);
}

int main() {
  input();
  solve();
  return 0;
}
