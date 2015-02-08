#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 110;

int n;
char s[maxn][maxn];
char ord[256][256];
int re[maxn][maxn];

void solve() {
  int flag = 0;
  memset(re, 0, sizeof(re));
  memset(ord, 0, sizeof(ord));
  for (int i = 0; i < maxn-1; ++ i) {
    for (int j = 0; j < n; ++ j) {
      for (int k = j+1; k < n; ++ k) {
        if (!re[j][k] && s[j][i] != s[k][i]) {
          re[j][k] = 1;
          char &tmp1 = ord[ s[j][i] ][ s[k][i] ];
          char &tmp2 = ord[ s[k][i] ][ s[j][i] ];
          if (!tmp1) {
            tmp1 = -1;
            tmp2 = 1;
          } else {
            if (tmp1 != -1) {
              flag = 1;
              goto here;
            }
          }
        }
      }
    }
  }
here:
  if (!flag) {
    char out[27];
    out[26] = 0;
    for (int i = 0; i < 26; ++ i) {
      int cnt[256];
      memset(cnt, 0, sizeof(cnt));
      for (int j = 'a'; j <= 'z'; ++ j) {
        for (int k = 'a'; k <= 'z'; ++ k) {
          if (j == k) continue;
          if (ord[j][k] == -1) {
            cnt[j] += 1;
          }
        }
      }
      char now = 0;
      for (int j = 'a'; j <= 'z'; ++ j) {
        if (cnt[j] == 0) {
          if (!now) {
            now = j;
          }
          else {
            printf("1Impossible\n");
            return;
          }
        }
      }
      for (int j = 'a'; j <= 'z'; ++ j) {
        ord[now][j] = -1;
        ord[j][now] = 0;
      }
      out[i] = now;
    }
    printf("%s\n", out);
  } else {
    printf("2Impossible\n");
  }
}

void out() {
}

int main() {
  memset(s, 0, sizeof(s));
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%s", s[i]);
  }
  solve();
  out();
  return 0;
}
