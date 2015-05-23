#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = (int)5e6+10;
int a, b;
int isprime[maxn];
vector<int> primes;
ll s[maxn];
ll c[maxn];

void solve() {
  printf("%lld\n", s[a]-s[b]);
}

inline
ll dp(int i) {
  if (c[i]) return c[i];
  return c[i] = 1+dp(i/isprime[i]);
  int bd = (int) sqrt (i) + 1;
  for (auto it = primes.begin(); it != primes.end() && *it < bd; ++ it) {
    if (i%(*it) == 0) {
      return c[i] = 1+dp(i/(*it));
    }
  }
  return c[i]=1;

}

void init() {
  int bd = (int) sqrt(maxn);
  for (int i = 2; i < bd; ++ i) if (!isprime[i]) {
    for (int k = i*i; k < maxn; k += i) {
      isprime[k] = i;
    }
  }

  for (int i = 2; i < maxn; ++ i) if (!isprime[i]){
    primes.push_back(i);
    c[i] = 1;
  }

  s[1] = 0;
  for (int i = 2; i < maxn; ++ i) {
    s[i] = s[i-1] + dp(i);
  }


}

int main() {
  init();

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &a, &b);
    solve();
  }

  return 0;
}

