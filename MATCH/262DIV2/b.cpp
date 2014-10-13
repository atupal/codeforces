#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

const int n = 9*9+1;

inline
int s(int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}


int ans[n*2];
int cnt = 0;

int cmp(int a, int b) {
  return a < b;
}

long long pow(int x, int y) {
  long long ret = 1;
  for (int i = 0; i < y; ++ i) {
    ret *= x;
  }
  return ret;
}

void solve() {
  int a, b,c ;
  scanf("%d %d %d", &a, &b,&c);
  for (int i = 0; i< n; ++ i) {
    long long x = (long long)b* pow(i, a) +c;
    if (s(x) == i and x < 1000000000 and x) {
      ans[cnt++] = x;
    }
  }
  sort(ans, ans+cnt, cmp);
  printf("%d\n", cnt);
  for (int i = 0; i < cnt-1; ++ i) {
    printf("%d ", ans[i]);
  }
  if (cnt) {
    printf("%d\n", ans[cnt-1]);
  }
}


int main() {
  solve();
  return 0;
}
