#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;

const int maxn = 100001;
int n;
int a[maxn];
char bits[maxn][20];
int len[maxn];

inline
int abs(int a) {
  return a < 0 ? -a : a;
}

ll get(int x, int a) {
  char *bitx = bits[x];
  char *bita = bits[a];
  int lx = len[x];
  int la = len[a];

  int l = 0;
  while (l+1 < la && l+1 < lx && bitx[l+1] == bita[l+1]) l++;
  for (int i = l+1; i < lx; ++ i) {
    if (bitx[i]) return (ll)maxn*(ll)maxn;
  }

  for (int i = l+1; i < la; ++ i) {
    if (bita[i]) {
      return (la-i)+abs(i-lx);
    }
  }

  return abs(la-lx);
}

ll getall(int x) {
  ll all = 0;

  for (int i = 0; i < n; ++ i) {
    ll add = get(x, a[i]);
    all += add;
  }

  return all;
}

void solve() {
  for (int i = 1; i < maxn; ++ i) {
    int x = i;
    len[i] = 0;
    while (x) {
      bits[i][len[i]++] = x&1;
      x >>=1;
    }
    for (int j = 0; j < len[i]/2; ++ j) {
      bits[i][j] ^= bits[i][len[i]-1-j] ^= bits[i][j] ^= bits[i][len[i]-1-j];
    }
  }

  ll ans = (ll)maxn*(ll)maxn;
  int t = a[0];
  while (t) {
    for (int i = t; i < maxn; i <<= 1) {
      ll m = getall(i);
      if (m < ans) {
        ans = m;
      }
    }
    t >>= 1;
  }

  printf("%d\n", (int)ans);
}

int main() {

  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a+i);
  }
  solve();

  return 0;
}

