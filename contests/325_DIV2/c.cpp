#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define lowbit(x) (x&(-x))

const int maxn = 4100;
int v[maxn], d[maxn], p[maxn];
int n;
int ans;
int out[maxn];
int H[maxn];
int s[maxn];

void modify(int p, int delta) {
  while (p <= n+1) {
    H[p] += delta;
    p += lowbit(p);
  }
}

typedef long long ll;
int sum(int p) {
  ll ret = 0;
  while (p) {
    ret += (ll) H[p];
    p -= lowbit(p);
  }

  if (ret > 10000000) return 10000000;

  return (int) ret;
}

void solve() {
  ans = 0;
  for (int i = 0; i < n; ++ i) {
    if (p[i] - sum(i) >= 0) {
      out[ans++] = i+1;

      int cnt = v[i];
      int j = i+1;
      while (j < n) {
        if (cnt==0) break;
        if (p[j] - sum(j) >= 0) {
          p[j] -= cnt;
          cnt --;
        }
        j ++;
      }


      for (int j = i+1; j < n; ++ j) {
        if (v[i] - (j-(i+1)) == 0) break;
        if (p[j] >= 0) {
          p[j] -= v[i] - (j-(i+1));
        } else {
          continue;
        }

        if (p[j] < 0) {
          modify(j+1, d[j]);
        }

      }
    }
  }

  printf("%d\n", ans);
  for (int i = 0; i < ans; ++ i) {
    printf("%d ", out[i]);
  }
}

int main() {
  scanf("%d", &n);
  for (int i= 0; i < n; ++ i) {
    scanf("%d %d %d", v+i, d+i, p+i);
  }
  
  solve();

  return 0;
}

