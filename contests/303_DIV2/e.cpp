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

typedef pair<int, int> P;

struct edge {
  int v;
  int idx;
  int w;
};

const ll INF = 1LL<<61;
const int maxn = (int) 3e5+10;
int n, m, root;
vector<edge> g[maxn];
ll ans;
ll d[maxn];
int w[maxn];
int idx[maxn];

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
    for (auto it=g[v].begin(); it != g[v].end(); ++ it) {
      if(d[it->v] >= d[v] + it->w) {

        if (d[it->v] == d[v] + it->w) {
          if (w[it->v] > it->w) {
            w[it->v] = it->w;
            idx[it->v] = it->idx;
          }
        } else {

          w[it->v] = it->w;
          idx[it->v] = it->idx;

          // no outside as equal should not push !, otherwise memory limit exceeded
          d[it->v] = d[v] + it->w;
          que.push(P(d[it->v],it->v));

        }

      }
    }
  }

}


void solve() {
  ans = 0;
  dijkstra();
  for (int i = 1; i <= n; ++ i) if (i != root) {
    ans += w[i];
  }
  cout << ans << endl;
  for (int i = 1; i <= n; ++ i) if (i != root) {
    cout << idx[i] << " ";
  }
}

int main() {

  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++ i) {
    int x, y, W;
    scanf("%d %d %d", &x, &y, &W);
    g[x].push_back( (edge) {y, i+1, W});
    g[y].push_back( (edge) {x, i+1, W});
  }

  scanf("%d", &root);

  solve();

  return 0;
}

