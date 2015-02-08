#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


const int maxn = (int)1e6 + 10;
char s[maxn];
typedef unsigned long long int64;
int64 a, b;
int l;

void solve() {
  int64 rest = 0;
  for (int i = 0; i < l-1; ++ i) {
    int64 now = rest+(int64) (s[i] - '0');
    int64 q = now / a;
    rest = now-q*a;
    rest*=10;
    if (not rest && s[i+1] != '0') {
      char *ss = &s[i+1];
      int64 restrest = 0;
      int ll = l - i+1;
      for (int ii = 0; ii < ll; ++ ii) {
        now = restrest+(int64) (ss[ii] - '0');
        q = now/b;
        restrest = now-q*b;
        restrest *= 10;
        if (not restrest && not ss[ii+1]) {
          char a = s[i+1];
          s[i+1] = 0;
          cout << "YES" << endl;
          cout << s << endl;;
          ss[0] = a;
          cout << ss << endl;
          return;
        }
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> s >> a >> b;
  l = strlen(s);
  if (l == 1) {
    cout << "NO" << endl;
    return 0;
  }
  solve();
  return 0;
}
