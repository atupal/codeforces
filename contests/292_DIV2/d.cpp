#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 2001;
int n, m;
char map[maxn][maxn];
char out[maxn][maxn];
int vis[maxn][maxn];
int ans = 0;

void dfs(int x, int y) {

  if (y==m) {
    x ++;
    y = 0;
  }

  if (x==n) {

    for (int i = n-1; i < n; ++ i) {
      for (int j = 0; j < m; ++ j) {
        if (map[i][j] == '.') {
          return;
        }
      }
    }

    if (ans) {
      printf("Not unique\n");
      exit(0);
    }
    ans = 1;
    memcpy(out, map, sizeof(map));
    return;
  }
  char cur='*', left='*', up='*', left_down='*', down='*', right='*';
  if (map[x][y] == '.') cur = '.';
  if (y-1>=0 && map[x][y-1]=='.') left = '.';
  if (x-1>=0 && map[x-1][y]=='.') up = '.';
  if (x+1<n && y-1>=0 && map[x+1][y-1]=='.') left_down='.';
  if (x+1<n && map[x+1][y] == '.') down='.';
  if (y+1<m && map[x][y+1] == '.') right='.';


  if ( cur == '.' ) {

    if (up=='.' && (left != '.' || left_down == '.')) {
      map[x-1][y] = '^';
      map[x][y] = 'v';
      dfs(x, y+1);
      map[x-1][y] = '.';
      map[x][y] = '.';
    } else if (y-1>=0 && map[x][y-1]=='.') {
      map[x][y-1] = '<';
      map[x][y] = '>';
      dfs(x, y+1);
      map[x][y-1] = '.';
      map[x][y] = '.';
    }
  }

  if (up=='.' || (left=='.' && left_down != '.') )  return;

  if (x-2>=0 && map[x-2][y]=='.') return;

  if (cur != '.' || down=='.' || right=='.') {
    dfs(x, y+1);
  }

}

void solve() {
  dfs(0, 0);
  if (!ans) {
    printf("Not unique\n");
    return;
  }
  for (int i = 0; i < n; ++ i) {
    printf("%s\n", out[i]);
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

