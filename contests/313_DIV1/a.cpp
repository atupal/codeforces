#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
ll a[7];

int main() {
  for (int i = 1; i <= 6; ++ i)
    scanf("%I64d", a+i);

  ll A = a[1] * (a[2] + a[3] - a[5]);
  A += a[2] * (a[3] + a[4]);
  A += a[3] * (a[4] + a[5]);
  A += a[4] * (a[5]);

  printf("%I64d\n", A);

  return 0;
}

