
#include <stdio.h>

int cnt = 0;

void fuck() {
  ++ cnt;
  printf("%d\n", cnt);
  fuck();
}

int main() {
  fuck();

  return 0;
}

