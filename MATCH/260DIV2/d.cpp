#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline
int min(int a, int b) {
  return a < b ? a : b;
}

const int maxn = 500010;
int n, k;
int flag[maxn], flag2[maxn];
char s[maxn];
int trie[maxn][26];
int cnt = 1;

void solve() {
  int ind, p;
  for (int i = 0; i < n; ++ i) {
    scanf("%s", s);
    p = 1;
    for (int x = 0; s[x]; ++ x) {
      ind = s[x] - 'a';
      if (!trie[p][ind]) {
        ++ cnt;
        trie[p][ind] = cnt;
      }
      p = trie[p][ind];
    }
  }

  for (int i = cnt; i; -- i) {
    int mv = 0;
    for (int j = 0; j < 26; ++ j) {
      if (trie[i][j]) {
        mv = 1;
        break;
      }
    }
    if (not mv) {
      flag[i] = 0;
      flag2[i] = 1;
    } else {
      flag[i] = 0;
      flag2[i] = 0;
      for (int j = 0; j < 26; ++ j) {
        if (trie[i][j]) {
          if (!flag[trie[i][j]]) {
            flag[i] = 1;
          }
          if (!flag2[trie[i][j]]) {
            flag2[i] = 1;
          }
        }
      }
    }
  }

  if ( (flag[1] and flag2[1]) or (flag[1] and not flag2[1] and k%2) ) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
}

int main() {
  scanf("%d %d", &n, &k);
  solve();

  return 0;
}
