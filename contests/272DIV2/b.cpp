#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s1[12], s2[12];
int ds = 0;
int s = 0;
int ans = 0;

void dfs(int ind) {
  if (not s2[ind]) {
    if (s == ds) ++ ans;
    return;
  }
  if (s2[ind] == '+') {
    ++ s;
    dfs(ind+1);
    -- s;
  } else if (s2[ind] == '-') { 
    -- s;
    dfs(ind+1);
    ++ s;
  } else {
    ++ s;
    dfs(ind+1);
    -- s;
    -- s;
    dfs(ind+1);
    ++ s;
  }
}

void solve() {
  int cnt = 1;
  for (int i = 0; s1[i]; ++ i) {
    if (s1[i] == '+') {
      ++ ds;
    } else {
      -- ds;
    }
  }
  for (int i = 0; s2[i]; ++ i) {
    if (s2[i] == '?') 
      cnt *= 2;
  }
  dfs(0);
  double tmp = (double)ans;
  printf("%.9lf\n", tmp/cnt);

}

int main() {
  scanf("%s", s1);
  scanf("%s", s2);
  solve();
  return 0;
}
