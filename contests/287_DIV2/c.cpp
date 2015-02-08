#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


const int maxn = 60;

typedef long long int64;
int64 h, n;
int64 exp[maxn];

int64 dfs (int64 h, int64 n, int type) {
  if (h == 1) return 1L;
  if (n <= exp[h-2]) {
    if (type == 1) {
      return 1L + dfs(h-1, n, 2);
    } else {
      return exp[h-1] + dfs(h-1, n, 2);
    }
  } else {
    if (type == 1) {
      return exp[h-1] + dfs(h-1, n-exp[h-2], 1);
    } else {
      return 1 + dfs(h-1, n-exp[h-2], 1);
    }
  }
}

void solve() {
  exp[0] = 1L;
  for (int i = 1; i < maxn; ++ i) {
    exp[i] = exp[i-1]*2;
  }
  cout << dfs(h+1, n, 1)-1;
}

int main() {
  cin >> h >> n;
  solve();

  return 0;
}
