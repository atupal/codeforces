#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef long long ll;

const ll maxn = 100010ll;
ll n, m, k;
ll a;
ll b;
ll pos[maxn];
ll map[maxn];

void solve() {
  ll ans = 0;
  for (int i = 0; i < m; ++ i) {
    cin >> b;
    b -= 1;

    ans += 1 + pos[b]/k;

    if (pos[b]) {
      pos[b] -= 1;
      map[ pos[b]+1 ] = map[ pos[b] ];
      pos[ map[ pos[b] ] ] = pos[b] + 1;
      map[ pos[b] ] = b;
    }

  }

  cout << ans << endl;
}

int main() {
  std::ios::sync_with_stdio(false);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++ i) {
    cin >> a;
    pos[a-1] = i;
    map[i] = a-1;
  }

  solve();

  return 0;
}

