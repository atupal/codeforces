#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef long long int64;

int n, x;
const int maxn = 100;
const int64 MOD = (int64)1e9 + 7;
int64 d[maxn+1];
int64 A[maxn+1][maxn+1];
int64 ret[maxn+1][maxn+1];
int64 base[maxn+1][maxn+1];
int64 tmp[maxn+1][maxn+1];
int64 X[1][maxn+1];


void mul(int64 a[][maxn+1], int64 b[][maxn+1]) {
  for (int i = 0; i < maxn+1; ++ i) {
    for (int j = 0; j < maxn+1; ++ j) {
      tmp[i][j] = 0;
      for (int k = 0; k < maxn+1; ++ k) {
        tmp[i][j] += a[i][k] * b[k][j];
        tmp[i][j] %= MOD;
      }
    }
  }
  memcpy(a, tmp, sizeof(tmp));
}

void solve() {
  cin >> n >> x;
  int64 t;
  memset(d, 0, sizeof(d));
  for (int i = 0; i < n; ++ i) {
    cin >> t;
    ++ d[t];
  }

  memset(A, 0, sizeof(A));
  memset(X[0], 0, sizeof(X[0]));
  X[0][maxn] = 1;

  for (int i = 0; i < maxn-1; ++ i) {
    A[i+1][i] = 1;
  }

  for (int i = 0; i < maxn; ++ i) {
    A[i][maxn-1] = d[maxn-i];
  }

  A[maxn][maxn-1] = 1;
  A[maxn][maxn] = 1;

  memcpy(ret, A, sizeof(A));
  memcpy(base, A, sizeof(A));

  while (x) {
    if (x&1) {
      mul(ret, base);
    }
    mul(base, base);
    x >>= 1;
  }

  int64 ans = 0;
  for (int i = 0; i < maxn+1; ++ i) {
    ans += X[0][i]* ret[i][maxn-1];
    ans %= MOD;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
