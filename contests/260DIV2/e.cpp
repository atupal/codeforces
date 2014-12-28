/*
   并查集
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 300003;

int n,m,q;
int p[maxn];
int rank[maxn];

int getset(int x) {
  if (p[x] == x) {
    return x;
  } else {
    return p[x] = getset(p[x]);
  }
}

void bind(int x, int y) {
  x = getset(x);
  y = getset(y);
  if (x == y) return;
  if (rank[x] > rank[y]) {
    p[y] = x;
  } else {
    if (rank[x] == rank[y]) {
      ++ rank[y];
    }
    p[x] = y;
  }
}

void input() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; ++ i) {
    p[i] = i;
  }
  for (int i = 0; i < m; ++ i)  {
  }
}

void solve() {
}

int main() {
  return 0;
}
