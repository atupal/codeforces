/*
   简单 dp
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef long long int64;

int64 n, k, m;

int64 _gcd(int64 a, int64 b) {
  if (a < b) a ^= b ^= a ^= b;
  return b==0? a : _gcd(b, a%b);
}

int64 memo[1001][101][101];

int64 dp(int pos, int pre, int gcd) {
  int64 &ret = memo[pos][digit][gcd];
  if (ret != -1) return ret;

  ret = 0L;
  for (int i = 1; i <= k; ++ i) {
    if ( _gcd( i*10+digit, k ) == gcd ) {
      for (int d=  0; d < k; ++ d) {
        ret += dp(pos-1, d, i);
        ret %= m;
      }
    }
  }

  return ret;
}

void solve() {
  memset(memo, -1, sizeof(memo));

  for (int i = 0; i < 10; ++ i) {
    for  (int j = 1; j <= k; ++ j) {
      memo[2][i][j] = 0;
    }
    if (i) memo[1][i][_gcd(i, k)] += 1;
  }

  int64 ans = 0;
  for (int i = 0; i < 10; ++ i) {
    ans += dp(n, i, k);
  }
  ans %= m;

  cout << ans << endl;
}

int main() {
  cin >> n >> k >> m;
  solve();

  return 0;
}
