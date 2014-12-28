#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = (int)1e5 * 2 + 100;

int n, m;
int a[maxn], b[maxn];

int* get(int d) {
  int reta = 0, retb = 0;
  for (int i = 0; i < n; ++ i) {
    if (a[i] > d) reta += 3;
    else reta += 2;
  }
  for (int i = 0; i < m; ++ i) {
    if (b[i] > d) retb += 3;
    else retb += 2;
  }

  int * ret = (int*) malloc (sizeof(int)*2);
  ret[0] = reta;
  ret[1] = retb;
  return ret;
  //return reta - retb;
}

void solve() {
}

inline
int max(int a, int b) {
  return a > b ? a : b;
}

inline
int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  scanf("%d", &n);
  double sa = 0, sb = 0;
  int maxa = 0;
  int maxb = 0;
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a+i);
    sa += a[i];
    maxa = max(maxa, a[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i< m; ++ i) {
    scanf("%d", b+i);
    sb += b[i];
    maxb = max(maxb, b[i]);
  }
  sa /= 1.0 * n;
  sb /= 1.0 * m;
  int *ret;
  if (sa >= sb) {
    ret = get(min(maxb, (int)sa));
  } else {
    ret = get(0);
  }
  printf("%d:%d\n", ret[0], ret[1]);

  return 0;
}
