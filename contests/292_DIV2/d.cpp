#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 2001;
int n, m;
char map[maxn][maxn];
int vis[maxn][maxn];

int get(int x, int y) {
  if (map[x][y] != '.') return 0;
  int ret = 0;
  if (x+1<n && map[x+1][y] == '.') ret ++;
  if (y+1<m && map[x][y+1] == '.') ret ++;
  if (x-1>=0&& map[x-1][y] == '.') ret ++;
  if (y-1>=0&& map[x][y-1] == '.') ret ++;

  return ret;
}

void solve() {
  queue <pair<int, int> > q;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      if (get(i, j) == 1) {
        q.push(make_pair(i, j));
      }
    }
  }

  while (!q.empty()) {
    __typeof(q.front()) it = q.front();
    q.pop();
    int x = it.first;
    int y = it.second;
    if (!vis[x][y]) {
      vis[x][y] = 1;
      if (x+1 < n && map[x+1][y] == '.') {
        map[x][y]   = '^';
        map[x+1][y] = 'v';
        vis[x+1][y] = 1;
      } else if (y+1 < m && map[x][y+1] == '.') {
        map[x][y]   = '<';
        map[x][y+1] = '>';
        vis[x][y+1] = 1;
      } else if (x-1 >= 0 && map[x-1][y] == '.') {
        map[x-1][y] = '^';
        map[x][y] = 'v';
        vis[x-1][y] = 1;
      } else if (y-1 >= 0 && map[x][y-1] == '.') {
        map[x][y-1] = '<';
        map[x][y] = '>';
        vis[x][y-1] = 1;
      }

      for (int i = x-2; i <= x+2; ++ i) {
        for (int j = y-2; j <= y+2; ++ j) {
          if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && get(i, j) == 1) {
            q.push(make_pair(i, j));
          }
        }
      }


    }

  }

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      if (map[i][j] == '.') {
        printf("Not unique\n");
        return;
      }
    }
  }

  for (int i = 0; i < n; ++ i) {
    printf("%s\n", map[i]);
  }

}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    scanf("%s", map[i]);
  }
  solve();

  return 0;
}
