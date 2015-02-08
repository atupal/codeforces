
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

const int maxn = (int)1e5+10;

char s[maxn];
int ans[maxn];
int l;

void solve() {
  int lcnt=0, rcnt=0, ccnt=0;
  for (char *i=s; *i; ++i) {
    if (*i == '(') lcnt++;
    else if (*i == ')') rcnt++;
    else ccnt++;
  }
  if (lcnt-rcnt<ccnt) {
    cout << -1 << endl;
    return;
  }
  int a = 0, b = 0, c = 0;
  for (char *i=s; *i; ++i) {
    if (*i == '(') a++;
    else if (*i == ')') b++;
    else {
      if (c < ccnt-1) {
        ans[c] = 1;
        b += 1;
      } else {
        ans[c] = lcnt-rcnt-(ccnt-1);
        b += ans[c];
      }
      c ++;
    }
    if (a < b) {
      cout << -1 << endl;
      return;
    }
  }
  for (int i = 0; i < ccnt; ++ i)
    cout << ans[i] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  l = strlen(s);

  solve();

  return 0;
}
