#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;


const int maxn = 1010;
int n, l;

int a[maxn];

inline
int get(double x) {
  for (int i = 1; i < n; ++ i) {
    if (a[i+1]-a[i] > x*2+1e-10) {
      return 0;
    }
  }
  if (a[1]-1e-10 > x) return 0;
  if (a[n+1] - a[n] - 1e-10> x) return 0;
  return 1;
}

void solve() {
  long double low = 0., high = l*2.;
  while (high - low >= 1e-9) {
    long double mid = (low + high) / 2.;
    if (get(mid)) {
      high = mid - 1e-9;
    } else {
      low = mid + 1e-9;
    }
  }
  printf("%.9lf", (double)low);
}

int main() {
  scanf("%d %d", &n, &l);
  a[0] = 0;
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a+i+1);
  }
  a[n+1] = l;
  sort(a+1, a+n+1);
  solve();

  return 0;
}
