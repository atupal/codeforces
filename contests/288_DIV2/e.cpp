#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 610;
int n;
int l[maxn], r[maxn];
int ans[maxn];
int vis[maxn];
char out[maxn];
int has_ans;

int get(int i) {
  int dis;
  if (l[i]&1) {
    dis = l[i];
  } else {
    dis = l[i]+1;
    if (dis>r[i]) {
      printf("IMPOSSIBLE\n");
      exit(0);
    }
  }
  return dis;
}

void dfs(int idx, int remain) {
  if (remain<0 || (idx==n && remain != 0) ) {
    printf("IMPOSSIBLE\n");
    exit(0);
  } else if (remain == 0) return;
  vis[idx] = 1;
  ans[idx] = get(idx);
  if (ans[idx] == 1) {
    dfs(idx+1, remain-2);
  } else {
    if ( ans[idx]+1 != remain ) {
      printf("IMPOSSIBLE\n");
      exit(0);
    } else {
      dfs(idx+1, remain-2);
    }
  }
}


void solve() {
  has_ans = 1;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; ++ i) {
    if (!vis[i]) {
      ans[i] = get(i);
      //printf("%d : %d\n", i, ans[i]);
      dfs(i+1, ans[i]-1);
    }
  }

  memset(out, '*', sizeof(out));
  out[n*2] = 0;
  int it = 0;
  for (int i = 0; i < n; ++ i) {
    while (out[it] == ')') it ++;
    out[it] = '(';
    out[it+ans[i]] = ')';
    it ++;
    //printf("%d - %d \n", i, ans[i]);
    //printf("%s\n", out);
  }
  printf("%s\n", out);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d %d", l+i, r+i);
  }
  solve();

  return 0;
}
