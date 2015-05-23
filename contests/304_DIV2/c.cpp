#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
using namespace std;
typedef long long ll;

map< pair<ll, ll>, int> vis;
int n, k1, k2;
ll a, b;
ll p[] = {
  1,
  10,
  100,
  1000,
  10000,
  100000,
  1000000,
  10000000,
  100000000,
  1000000000,
  10000000000,
  100000000000,
  10000000000000,
  100000000000000,
  1000000000000000
};

void solve() {
  int cnt = 0;
  ll p1, p2;
  while (k1&&k2) {
    cnt += 1;
    p1 = a%10;
    p2 = b%10;
    a /= 10;
    b /= 10;
    k1 --;
    k2 --;
    if (p1 > p2) {
      a += p2*p[k1];
      k1 ++;
      a += p1*p[k1];
      k1 ++;
    } else {
      b += p1*p[k2];
      k2 ++;
      b += p2*p[k2];
      k2 ++;
    }
    if (vis[make_pair(a+k1*p[12], b+k2*p[12])] == 1) {
      printf("-1\n");
      return;
    } else {
      vis[make_pair(a+k1*p[12], b+k2*p[12])] = 1;
    }
  }

  printf("%d %d\n", cnt, k2==0?1:2);
}

int main() {
  scanf("%d", &n);
  a = b = 0;
  scanf("%d", &k1);
  for (int i = 0; i < k1; ++ i) {
    int t;
    scanf("%d", &t);
    -- t;
    a += p[i] * (ll)t;
  }
  scanf("%d", &k2);
  for (int i = 0; i < k2; ++ i) {
    int t;
    scanf("%d", &t);
    -- t;
    b += p[i] * (ll)t;
  }
  solve();

  return 0;
}

