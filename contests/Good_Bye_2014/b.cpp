#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 310;
char s[maxn][maxn];
int n;
int pos[maxn];
int ans[maxn];
int vis[maxn];

inline
int min(int a, int b) {
  return a < b ? a : b;
}

int min_pos;
int checkpoint_pos[maxn];
int checkpoint_ans[maxn];
void dfs(int x) {
  if ( pos[x] < min_pos) {
    int flag = 1;
    for (int i = 1; i < x; ++ i) {
      if ( pos[i] != checkpoint_pos[i]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      min_pos = pos[x];
      memcpy(checkpoint_pos, pos, sizeof(pos));
      memcpy(checkpoint_ans, ans, sizeof(ans));
    }
  }
  for (int i = 0; i < n; ++ i) {
    if ( !vis[i] && s[pos[x]][i] == '1') {
      vis[i] = 1;
      int a = pos[x];
      int b = pos[ans[i]];
      int c = ans[i];
      int d = ans[pos[x]];
      ans[i] ^= ans[a] ^= ans[i] ^= ans[a];
      pos[x] = i;
      pos[c] = a;
      dfs(x);
      pos[x] = a;
      pos[c] = b;
      ans[i] = c;
      ans[a] = d;
      vis[i] = 0;
    }
  }
}

void solve() {
  memcpy(checkpoint_pos, pos, sizeof(pos));
  memcpy(checkpoint_ans, ans, sizeof(ans));
  for (int i = 1; i <= n; ++ i) {
    memset(vis, 0, sizeof(vis));
    vis[pos[i]] = 1;
    min_pos = n;
    dfs(i);

    for (int i = 0; i < n; ++ i) {
      printf("%d ", checkpoint_ans[i]);
    }
    printf("\n");

    memcpy(pos, checkpoint_pos, sizeof(pos));
    memcpy(ans, checkpoint_ans, sizeof(ans));
  }
  for (int i = 0; i < n; ++ i) {
    printf("%d ", checkpoint_ans[i]);
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", ans+i);
    pos[ ans[i] ] = i;
  }
  for (int i = 0; i < n; ++ i) {
    scanf("%s", s[i]);
  }
  solve();

  return 0;
}
