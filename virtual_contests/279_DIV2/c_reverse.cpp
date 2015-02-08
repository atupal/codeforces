#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


const int maxn = (int)1e6 + 10;
char ss[maxn];
typedef unsigned long long int64;
int64 a, b;

void reverse(char *s) {
  int l = strlen(s);
  for (int i = 0; i < l/2; ++ i) {
    s[i] ^= s[l-1-i] ^= s[i] ^= s[l-1-i];
  }
}

int getans = 0;
int pos = -1;
int begin = 1;
void dfs(char *s, int64 base, int64 rest, int ind, int cnt) {
  if (getans) return;
  if (not rest and not begin) {
    if (ind == 1 && *(s-1) != '0') {
      pos = cnt;
      dfs(s, b, rest, 2, cnt);
      return;
    } else if (ind == 2) {
      if (not *s) {
        cout << "YES" << endl;
        int l = strlen(ss);
        for (int i = l-1; i >= pos; -- i) {
          cout << ss[i];
        }
        cout << endl;
        for (int i = pos-1; i >= 0; -- i) {
          cout << ss[i];
        }
        cout << endl;
        getans = 1;
      }
    }
    //return;
  }
  if (not *s) return;
  begin = 0;
  for (int64 i = 0; i < 10; ++ i) {
    int64 now = i*base+rest;
    if ( now%10 == (int64) (*s - '0') ) {
      dfs(s+1, base, now/10, ind, cnt+1);
    }
  }
}

void solve() {
  dfs(ss, a, 0, 1, 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin >> ss >> b >> a;
  reverse(ss);
  solve();
  if (not getans) {
    cout << "NO" << endl;
  }

  return 0;
}
