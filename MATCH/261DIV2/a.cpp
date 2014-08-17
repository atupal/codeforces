
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


inline
int abs(int a) {
  return a > 0 ? a : -a;
}

inline
int max(int a, int b ) {
  return a > b ? a : b;
}

inline
int min(int a, int b) {
  return a < b ? a : b;
}

void solve()  {
  int x1, y1, x2,y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  if (not abs(y1-y2)) {
    printf("%d %d %d %d\n", x1, y1+abs(x1-x2), x2, y2+abs(x1-x2));
  } else if (not abs(x1-x2)) {
    printf("%d %d %d %d\n", x1+abs(y1-y2), y1, x2+abs(y1-y2), y2);
  } else if (abs(x1-x2) == abs(y1-y2)) {
    printf("%d %d %d %d\n", x1, y2, x2, y1);
  } else {
    printf("-1\n");
  }
}

int main() {
  solve();
  return 0;
}
