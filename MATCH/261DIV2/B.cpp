
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <algorithm>

//using namespace std;

const int maxn = 200010;
long long n;
unsigned int b[maxn];
unsigned int max = 0;
unsigned int min=1000000001;

void input() {
  scanf("%I64d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%Id", b+i);
    max = b[i] > max ? b[i] : max;
    min = b[i] < min ? b[i] : min;
  }
}


void solve() {
  printf("%Id ", max - min);
  long long nmax = 0, nmin = 0;
  for (int i = 0 ; i<  n; ++ i) {
    nmax += (b[i] == max);
    nmin += (b[i] == min);
  }
  if (max!=min) {
    printf("%I64d\n", nmax*nmin);
  } else {
    printf("%I64d\n", n*(n-1)/2);
  }
}

int main() {
  input();
  solve();

  return 0;
}
