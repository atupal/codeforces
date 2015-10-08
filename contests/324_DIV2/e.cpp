#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 2010;
int n;
int tmp[maxn*maxn];
int a[maxn];
int k;
int times;

inline
int abs(int a) {
  return a < 0 ? -a : a;
}

/*
 * implement a sort that make that every swap can make two elements closer their finally positon;
 * */
void solve() {
  k = 0;
  times = 0;

  while (1) {
    int flag = 1;
    int flag2 = 1;

    for (int i = 1; i <= n; ++ i) {
      if (a[i] != i) {
        if ( (a[i] > i && a[a[i]] < a[i] && i >= a[a[i]]) ||
             (a[i] < i && a[a[i]] > a[i] && i <= a[a[i]])) {
          int idx = i;
          int idy = a[i];
          a[idx] ^= a[idy] ^= a[idx] ^= a[idy];
          tmp[times++] = idx*maxn + idy;
          k += abs(idx-idy);
          flag2 = 0;
        }
        flag = 0;
      }
    }

    if (flag) break;

    if (flag2) {
      for (int i = 1; i < n; ++ i) if (a[i] > i) {
        for (int j = i+1; j <= n; ++ j) if (a[j] < j) {
          if (a[i] >= j && a[j] <= i) {
            a[i] ^= a[j] ^= a[i] ^= a[j];
            tmp[times++] = i*maxn + j;
            k += j-i;
            flag2 = 0;
          }
        }
      }
    }
  }

  printf("%d\n", k);
  printf("%d\n", times);
  for (int i = 0; i < times; ++ i) {
    printf("%d %d\n", tmp[i]/maxn, tmp[i]%maxn);
  }
}

int main() {
  scanf("%d", &n);
  int t;
  /*
   * re-position to 1,2,3,4,5.....n
   * */
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", &t);
    tmp[t] = i;
  }
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", &t);
    a[tmp[t]] = i;
  }

  //for (int i = 1; i <= n; ++ i) {
    //printf("%d ", a[i]);
  //}
  //printf("\n");

  solve();

  return 0;
}

