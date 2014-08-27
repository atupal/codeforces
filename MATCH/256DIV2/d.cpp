#include <iostream>
using namespace std;

typedef long long int64;
int n, m;
int64 k;
// 小于或等于 x 的数
#define min(a,b) ((a)<(b)?(a):(b))
inline
int64 f(int64 x) {
  int64 ans = 0;
  for (int i = 1; i <= n; ++ i) {
    ans += min((int64) x / i, m);
  }
  return ans;
}

void solve() {
  int64 low = 1, high = (int64) n * m, mid;
  while (low < high) {
    mid = (low + high) >> 1;
    if (f(mid) < k) {
      low = mid + 1;
    }  else {
      high = mid;
    }
  }
  cout << low;
}

int main() {
  cin >> n >> m >> k;
  solve();
  return 0;
}
