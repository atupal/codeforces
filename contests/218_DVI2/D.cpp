#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 1000000;
int n, m;
int B[maxn], A[maxn], C[maxn];

void add(int x) {
  while ( x <= n ) {
    C[x] ++;
    x += ( x & (-x) );
  }
}

void rem(int x) {
  while ( x <= n ) {
    C[x] --;
    x += ( x & (-x) );
  }
}

int get(int x) {
  int ret = 0;
  while ( x > 0 ) {
    ret += C[x];
    x -= ( x & (-x) );
  }
  return ret;
}

int find(int y) {
  int tmp = get( y - 1);
  int lef = y - 1;
  int rig = n + 1;
  while ( lef < rig - 1) {
    int mid = ( lef + rig) >> 1;
    if ( get(mid) == tmp ) {
      lef = mid;
    } else {
      rig = mid;
    }
  }

  return rig;
}


int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++ i) {
    add(i);
    scanf("%d", B+i);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++ i) {
    int x, y, z;
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d %d", &y, &z);
      while ( y < n + 1 and z > 0 ) {
        y = find(y);
        if ( y < n + 1 ) {
          A[y] += z;
          z = 0;
          if (B[y] < A[y]) {
            z = A[y] - B[y];
            A[y] = B[y];
            rem(y);
          }
        }
      }
    } else {
      int c;
      scanf("%d", &c);
      printf("%d\n", A[c]);
    }
  }
}
