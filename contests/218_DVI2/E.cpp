#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 300003;
const double mm = 10e60;
int n, k;
int A[maxn];
int B[maxn];
int ans = 0;
double dis = mm;

void swap(int i, int j) {
  if (A[i] != A[j]) 
    A[i] ^= A[j] ^= A[i] ^= A[j];
  if (B[i] != B[j])
    B[i] ^= B[j] ^= B[i] ^= B[j];
}

int part(int l, int r) {
  int p = l;
  for (int i = l+1; i <= r; ++ i) {
    if ( A[i] < A[l] ) {
      swap(i, ++p);
    }
  }
  swap(l, p);

  return p;
}

void sort(int l, int r) {
  while (l < r) {
    int p = part(l, r);
    sort(l, p);
    l = p + 1;
  }
}

double get(int x) {
  double ret = 0.0;
  for (int i = x+1; i < x + k; ++ i) {
    int ind = i - x;
    ret += (double)(A[i] - A[i - 1]) * (double)( ind * (k - ind) );
    if ( ret >= dis ) {
      return mm;
    }
  }

  return ret;
}

int main() {
  printf("%lf\n", mm);
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", A+i);
    B[i] = i+1;
  }
  scanf("%d", &k);
  sort(0, n-1);

  for (int i = 0; i < n - k + 1; ++ i) {
    double t = get(i);
    if ( t < dis ) {
      ans = i;
      dis = t;
    }
  }

  for (int i = 0; i < k; ++ i) {
    printf("%d ", B[i+ans]);
  }
  printf("\n");

  return 0;
}
