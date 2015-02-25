#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
const ll maxn = 100010;
const ll inf = 1e17+1e6;
ll n, k;
ll a[maxn];
char s[256];

inline
ll min(ll a, ll b) {
  return a < b ? a : b;
}
inline
ll max(ll a, ll b) {
  return a > b ? a : b;
}

void solve() {
  if (n == 1) {
    if (a[0] == inf) {
      printf("0\n");
    } else {
      printf("%I64d\n", a[0]);
    }
    return;
  }

  for (ll i = 0; i<min(k, n-k); ++i) {
    ll low = -inf;
    ll p = i;
    while (p < n) {
      if (a[p] != inf) {
        if (a[p] <= low) {
          printf("Incorrect sequence\n");
          return;
        }
        low = a[p];
        p += k;
        continue;
      }

      ll q = p+k;
      while (q < n && a[q]==inf) q += k;

      ll high;
      if (q < n) {
        high = a[q];
      } else {
        high = inf;
      }

      if ( high - low - 1ll < (q-p)/k) {
        printf("Incorrect sequence\n");
        return;
      }
      ll l = - ( (q-p)/k-1ll ) / 2ll;
      ll r = ( (q-p)/k-1ll ) / 2ll;
      if ( (q-p)/k%2 == 0 ) r+=1;
      if (l <= low) {
        l = low+1ll;
      }
      if (r >= high) {
        l -= r-high+1ll;
      }
      for (ll j = p; j < q; j += k) {
        a[j] = l+(j-p)/k;
        low = a[j];
      }
      p = q;

    }
  }

  for (ll i = 0; i < n; ++ i) {
    if (a[i] != inf) {
      printf("%I64d ", a[i]);
    } else {
      printf("0 ");
    }
  }

}

int main() {
  scanf("%I64d %I64d", &n, &k);
  for (ll i = 0; i < n; ++ i) {
    scanf("%s", s);
    if (s[0] == '?') {
      a[i] = inf;
    } else {
      sscanf(s, "%I64d", a+i);
    }
  }

  solve();

  return 0;
}

