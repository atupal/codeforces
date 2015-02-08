/*
   搜索 + 贪心

   bfs 找最短路径，然后贪心更新
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define triple(x, y, z) make_pair( make_pair(x, y), z)
#define first(x) x.first.first
#define second(x) x.first.second
#define third(x) x.second

using namespace std;

const int maxn = 100010;
int n, m;
int sum;

map <int, int> g[maxn];
int vis[maxn];
int p[maxn];
int s[maxn];
int t[maxn];

void solve() {
  queue <pair<int, int> >  q;
  memset(p, -1, sizeof(p));
  memset(vis, 0, sizeof(vis));
  vis[1] = 1;
  s[1] = 0;
  q.push(make_pair(1, 0));
  while (!q.empty()) {
    int x = q.front().first; 
    int y = q.front().second;
    q.pop();

    if (x == n) {
      break;
    }

    for (map<int, int>::iterator it = g[x].begin(); it != g[x].end(); ++ it) {
      if ( vis[it->first] ) {
        if ( vis[x]+ !(it->second-1) < vis[it->first] && y+1 == s[it->first]) {
          vis[ it->first ] = vis[x] + !(it->second-1);
          p[ it->first ] = x;
        }
      } else {
        q.push(make_pair(it->first, y+1));
        vis[ it->first ] = vis[x] + !(it->second-1);
        p[ it->first ] = x;
        s[ it->first ] = y+1;
      }
    }
  }

  int pre = n;
  int now = p[n];
  int cnt1 = 0, cnt2 = 0;
  do {
    if ( g[pre][now] == 1) {
      cnt1 += 1;
      g[pre][now] = 3;
      g[now][pre] = 0;
    } else {
      cnt2 += 1;
      g[pre][now] = 0;
      g[now][pre] = 0;
    }
    pre = now;
    now = p[now];
  } while (now != -1);

  printf("%d\n", sum-cnt2+cnt1);

  for (int i = 1; i <= n; ++ i) {
    for (auto it = g[i].begin(); it != g[i].end(); ++ it) {
      if (it->second == 2 && g[it->first][i] == 2) {
        g[i][it->first] = 0;
      }
    }
  }


  for (int i = 1; i <= n; ++ i) {
    for (auto it = g[i].begin(); it != g[i].end(); ++ it) {
      if ( it->second == 2 ) {
        printf("%d %d %d\n", i, it->first, 0);
      } else if (it->second == 3 ) {
        printf("%d %d %d\n", i, it->first, 1);
      }
    }
  }

}

int main() {
  scanf("%d %d", &n, &m);
  sum = 0;
  for (int i = 0; i < m; ++ i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    g[x][y] = z+1;
    g[y][x] = z+1;
    sum += z;
  }

  solve();

  return 0;
}
