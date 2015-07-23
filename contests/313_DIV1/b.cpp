#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn =  200002;
char a[maxn];
char b[maxn];
int cnta[maxn][26];
int cntb[maxn][26];

inline
int eq(int x, int y, int l) {

  for (int i = 0; i < 26; ++ i) {
    if (cnta[x+l][i] - cnta[x][i] != cntb[y+l][i] - cntb[y][i]) return 0;
  }

  if (l&1) {
    for (int i = 0; i < l; ++ i) {
      if (a[x+i] != b[y+i]) return 0;
    }

    return 1;
  }

  l >>= 1;
  if ( (eq(x, y, l) && eq(x+l, y+l, l)) || (eq(x, y+l, l) && eq(x+l, y, l))) return 1;
  return 0;
}


/*
 * another way is sort the tow string, and then compare
 * first we sort the tow halves, and then rescursive sort these two halves
 * */
int main() {
  scanf("%s %s", a, b);
  int l = 0;
  for (int i = 0; i < 26; ++ i) {
    cnta[0][i] = cntb[0][i] = 0;
  }
  for (; a[l]; l++) {
    for (int i = 0; i < 26; ++ i) {
      cnta[l+1][i] = cnta[l][i];
      cntb[l+1][i] = cntb[l][i];
    }
    cnta[l+1][a[l]-'a'] ++;
    cntb[l+1][b[l]-'a'] ++;
  }

  if (eq(0, 0, l)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}

