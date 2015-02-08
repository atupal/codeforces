#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

const int maxn = 100010;
int n;
int a[maxn];
int b[maxn];
struct p {
  int s;
  int t;
  p(int a, int b) {
    s = a;
    t = b;
  }
  void print() {
    printf("%d %d\n", s, t);
  }
};

vector <p> ans;

void solve() {
  for (int t = n; t; --t) {

    int *A, *B;
    A = a;
    B = b;
    int low = 1;
    int cnt = 0;
    //for (int score = t; score <= A[n]; score += t) {
    while (low <= n) {
      int t1 = get(A, low, A[low-1]+t);
      int t2 = get(B, low, B[low-1]+t);
      if (t1 != -1 && ( t1 < t2 || t2 == -1) ) {
        low = t1+1;
        cnt += 1;
      }
      if (t2 != -1 && (t2 < t1 || t1 == -1) ) {
        low = t2 + 1;
      }
      if (t1 == -1 && t2 == -1) break;
    }
    if (low == n+1) {
      ans.push_back(p(A[n]/t, t));
    }
  }
  int k = (int)ans.size();
  printf("%d\n", k);
  for (int i = 0; i < k; ++ i) {
    ans[i].print();
  }
}

int main() {
  scanf("%d", &n);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= n; ++ i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      a[i] = a[i-1] + 1;
      b[i] = b[i-1];
    } else {
      a[i] = a[i-1];
      b[i] = b[i-1] + 1;
    }
  }
  solve();
  return 0;
}
