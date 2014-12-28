#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dp1(x) (momo1[x] != -1 ? momo1[x] : _dp1(x))
#define dp2(x) (momo2[x] != -1 ? momo2[x] : _dp2(x))

const int MOD = 1000000007;
const int maxn = 100010;
int n;
int col[maxn];
int momo1[maxn];
int momo2[maxn];

static struct edge {
  int v;
  edge *next;
} chi[maxn];

void input() {
  scanf("%d", &n);
  int v;
  for (int i = 1; i < n; ++ i) {
    scanf("%d", &v);
    edge *tmp = (edge*) malloc (sizeof(edge));
    tmp->v = i;
    tmp->next = chi[v].next;
    chi[v].next = tmp;
  }
  for (int i = 0; i< n; ++ i) {
    scanf("%d", col+i);
  }
  for (int i = 0; i <n ; ++ i) {
    edge *tmp = chi[i].next;
    while (tmp) {
      //printf("%d ", tmp->v);
      tmp = tmp->next;
    }
    //printf("\n");
  }
  memset(momo1, -1, sizeof(momo1));
  memset(momo2, -1, sizeof(momo2));
}

int _dp2(int x);
int _dp1(int x) {
  int ans = 0;
  if (col[x]) {
    edge *tmp = chi[x].next;
    if (not tmp) {
      ans = 1;
    } else {
      int mul = 1;
      while (tmp) {
        mul *= dp1(tmp->v);
        tmp = tmp->next;
      }
      tmp = chi[x].next;
      while (tmp) {
        if (dp1(tmp->v))
        ans += dp2(tmp->v) * mul / dp1(tmp->v);
        tmp = tmp->next;
      }
      ans += mul;
    }
  } else {
    edge *tmp = chi[x].next;
    int cnt = 0;
    int mul = 1;
    while (tmp) {
      ++ cnt;
      mul *= dp1(tmp->v);
      tmp = tmp->next;
    }
    ans = cnt * mul;
  }
  return momo1[x] = ans;
}

int _dp2(int x) {
  int ans = 0;
  if (col[x]) {
  } else {
    edge *tmp = chi[x].next;
    if (not tmp) {
      ans = 1;
    } else {
      int mul = 1;
      while (tmp) {
        mul *= dp1(tmp->v);
        tmp = tmp->next;
      }
      tmp = chi[x].next;
      while (tmp) {
        if (dp1(tmp->v))
        ans += dp2(tmp->v) * mul / dp1(tmp->v);
        tmp = tmp->next;
      }
      ans += mul;
    }
  }
  return momo2[x] = ans;
}

void solve() {
  printf("%d\n", dp1(0));
}

int main() {
  input();
  solve();
  return 0;
}
