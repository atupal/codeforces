#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


typedef long long int64;
int64 l, r;

int64 get(int64 l, int64 r) {
  for (int i = 62; i>=0; --i) {
    if ((r>>i)&1) {
      if ((l>>i)&1) {
        return ((int64)1L<<i) + get(l-((int64)1L<<i), r-((int64)1L<<i));
      }
      for (int j = i-1; j>=0; -- j) {
        if (  !((r>>j)&1)  ) {
          return ((int64)1L<<i) - 1;
        }
      }
      return ((int64)1L<<(i+1)) - 1;
    }
  }
  return 0L;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i= 0; i <n; ++ i) {
    cin >> l >> r;
    cout << get(l, r) << endl;
  }

  return 0;
}
