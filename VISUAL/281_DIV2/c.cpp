#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = (int)1e5 * 2 + 100;

int n, m;
int a[maxn], b[maxn];

int get(int *A, int n, int d) {
  int low = 0, high = n-1;
  while (low < high) {
    int mid = (low + high) >> 1;
    if ( A[mid] <= d) {
      low = mid+1;
    } else {
      high = mid-1;
    }
  }
  while (low < n && A[low] <= d) {
    low += 1;
  }
  return n*2 + n-low;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a+i);
  }
  scanf("%d", &m);
  for (int i = 0; i< m; ++ i) {
    scanf("%d", b+i);
  }
  sort(a, a+n);
  sort(b, b+m);
  int ans = 0;
  int max = get(a, n, 0) - get(b, m, 0);
  for (int i = 0; i < n; ++ i) {
    int t = get(a, n, a[i]) - get(b, m, a[i]);
    if (t > max || (t==max && get(a, n, a[i]) > get(a, n, ans))) {
      ans = a[i];
      max = t;
    }
  }
  for (int i = 0; i < m; ++ i) {
    int t = get(a, n, b[i]) - get(b, m, b[i]);
    if (t > max || (t==max && get(a, n, b[i]) > get(a, n, ans))) {
      ans = b[i];
      max = t;
    }
  }
  printf("%d:%d\n", get(a, n, ans), get(b, m, ans));

  return 0;
}
