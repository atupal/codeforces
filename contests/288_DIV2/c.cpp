#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 310;

int m, t, r;
int ghost[maxn];


void solve() {
}

int main() {
  scanf("%d %d %d", &m, &t, &r);
  for (int i = 0; i < m; ++ i) {
    scanf("%d", ghost+i);
  }
  solve();

  return 0;
}
