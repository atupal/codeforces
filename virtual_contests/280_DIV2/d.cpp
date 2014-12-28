#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int64;

const int64 maxn = 110000;

int64 n, x, y;
int64 a;

int64 get1(int64 n) {
  return n+ (n*y/x) >= a;
}

int64 get2(int64 n) {
  return n+ (n*x/y) >= a;
}

void solve () {
  int64 low = 0, high = a;
  while (low < high) {
    int64 mid = (low+high)>>1;
    if (get1(mid)) {
      high = mid;
    } else {
      low = mid+1;
    }
  }
  while (!get1(low)) low ++;
  int64 low1 = low;
  long long ans1 = (long long)low * (long long)y;

  low = 0, high = a;
  while (low < high) {
    int64 mid = (low+high)>>1;
    if (get2(mid)) {
      high = mid;
    } else {
      low = mid+1;
    }
  }
  while (!get2(low)) low ++;
  int64 low2 = low;
  long long ans2 = (long long)low * (long long)x;

  if (ans1 < ans2 || ( ans1 == ans2 && low1-1+low1*y/x < a && !(low2-1+low2*x/y<a)  )) {
    printf("Vanya\n");
  } else if (ans2 < ans1 || ( ans1 == ans2 && low2-1+low2*x/y < a && !(low1-1+low1*y/x<a) )) {
    printf("Vova\n");
  } else {
    printf("Both\n");
  }
}

int main() {
  scanf("%I64d%I64d%I64d", &n, &x, &y);
  for (int64 i = 0; i < n; ++ i) {
    scanf("%I64d", &a);
    solve();
  }
  return 0;
}
