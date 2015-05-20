#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

typedef pair<ll, ll> P;

const ll INF = 1LL<<61;
const int maxn = (int) 3e5+10;
int n, m, root;
unordered_map<int, ll> w[maxn];
unordered_map<int, int> idx[maxn];
vector<int> out;
ll ans;
char vis[maxn];
ll d[maxn];

void dijkstra() {
  priority_queue<P, vector<P>, greater<P> > que;  
  for (int i = 1; i <= n; ++ i) {
    d[i] = INF;
  }

  d[root] = 0;
  que.push(P(0, root));
  while(!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for (auto it=w[v].begin(); it != w[v].end(); ++ it) {
      if(d[it->first] > d[v] + it->second) {
        d[it->first] = d[v] + it->second;
        que.push(P(d[it->first],it->first));
      }
    }
  }

}


void dfs(int u, ll l) {
  vector<P> tmp;
  for (auto it = w[u].begin(); it != w[u].end(); ++ it) {
    tmp.push_back( make_pair(it->second, it->first) );
  }
  sort(tmp.begin(), tmp.end());

  //for (auto it = w[u].begin(); it != w[u].end(); ++ it) {
  for (auto i = tmp.begin(); i != tmp.end(); ++ i) {
    P *it = &(*i);
    it->first ^= it->second ^= it->first ^= it->second;

    if (vis[it->first]) continue;

    if (l + it->second <= d[it->first]) {
      vis[it->first] = 1;
      ans += it->second;
      out.push_back( idx[u][it->first] );
      dfs(it->first, l+it->second);
    }

  }

}

void solve() {
  dijkstra();
  ans = 0;
  memset(vis, 0, sizeof(vis));
  vis[root] = 1;
  dfs(root, 0);
  cout << ans << endl;
  for (auto it=out.begin(); it!=out.end(); ++ it) {
    cout << *it << " ";
  }
}

int main() {
  scanf("%d %d", &n, &m);

  for (ll i = 0; i < m; ++ i) {
    int x, y, W;
    scanf("%d %d %d", &x, &y, &W);
    w[x][y] = (ll)W;
    w[y][x] = (ll)W;
    idx[x][y] = i+1;
    idx[y][x] = i+1;
  }

  scanf("%d", &root);

  solve();

  return 0;
}

