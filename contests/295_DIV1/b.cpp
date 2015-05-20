#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1e5+1;
ll m;
const ll MOD = (ll)1e9+9;
ll a[maxn];
map<pair<ll, ll>, ll> s;
map<ll, ll> del;
int vis[maxn];

struct cube1 {
  ll x;
  ll y;
  ll idx;
  friend bool operator < (cube1 a, cube1 b) {
    return a.idx < b.idx;
  }
  cube1(){};
  cube1(ll a, ll b, ll c) {
    x = a;
    y = b;
    idx = c;
  }
};

struct cube2 {
  ll x;
  ll y;
  ll idx;
  friend bool operator < (cube2 a, cube2 b) {
    return a.idx > b.idx;
  }
  cube2(){};
  cube2(ll a, ll b, ll c) {
    x = a;
    y = b;
    idx = c;
  }
};

priority_queue<cube1> maxq;
priority_queue<cube2> minq;

int isstable(ll x, ll y) {
  for (ll i = x-1; i <= x+1; ++ i) {
    for (ll j=y-1; j <= y-1; ++ j) {
      if ( s[make_pair(i, j)] ) {
        return 1;
      }
    }
  }
  return 0;
}

#define abs(x) ( (x)<0?(-(x)):(x) )
int check(ll x, ll y) {
  if (!s[make_pair(x, y)]) return 0;
  ll tmp = s[make_pair(x, y)];
  s[make_pair(x, y)] = 0;
  for (ll i = x-1; i <= x+1; ++ i) {
    for (ll j=y+1; j <= y+1; ++ j) if(s[make_pair(i, j)]) {
      if ( !isstable(i, j) ) {
        s[make_pair(x, y)] = tmp;
        return 0;
      }
    }
  }
  s[make_pair(x, y)] = tmp;
  return 1;
}

void solve() {
  memset(vis, 0, sizeof(vis));
  for (__typeof(s.begin()) it = s.begin(); it != s.end(); ++ it) {
    pair<ll, ll> p = it->first;
    if (!vis[it->second] && check(p.first, p.second)) {
      maxq.push( cube1( p.first, p.second, it->second ) );
      minq.push( cube2( p.first, p.second, it->second ) );
      vis[it->second] = 1;
    }
  }

  int cnt = 0;
  while (1) {
    ll x, y;
    if (cnt%2==0) {
      cube1 c ;
      while (1) {
        c = maxq.top(); maxq.pop();
        if (!del[c.idx]) break;
      }
      a[cnt++] = c.idx;
      del[c.idx] = 1;
      x = c.x;
      y = c.y;
    } else {
      cube2 c ;
      while (1) {
        c = minq.top(); minq.pop();
        if (!del[c.idx]) break;
      }
      a[cnt++] = c.idx;
      del[c.idx] = 1;
      x = c.x;
      y = c.y;
    }
    s[make_pair(x, y)] = 0;

    for (ll i = x-1; i <= x+1; ++ i) {
      for (ll j = y-1; j <= y-1; ++ j) {
        if (!vis[s[make_pair(i, j)]] && check(i, j)) {
          maxq.push(cube1(i, j, s[make_pair(i, j)]));
          minq.push(cube2(i, j, s[make_pair(i, j)]));
          vis[s[make_pair(i, j)]] = 1;
        }
      }
    }
    if (cnt==m) break;

  }

  ll ans = 0;
  for (int i = 0; i < m; ++ i) {
    ans = ans*m%MOD + a[i]-1;
    ans %= MOD;
  }

  cout << ans << endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> m;
  ll x, y;
  for (int i = 0; i < m; ++ i) {
    cin >> x >> y;
    s[make_pair(x, y)] = i+1;
  }
  solve();

  return 0;
}

