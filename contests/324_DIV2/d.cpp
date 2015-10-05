#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
const int maxn = 100000;
char isprime[maxn];


#include <math.h>
bool isPrime (int num)
{
    if (num <=1)
        return false;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

int main() {
  scanf("%d", &n);
  if (n == 3) {
    printf("1\n3");
    return 0;
  }
  if (n == 4) {
    printf("2\n2 2\n");
    return 0;
  }
  if (n == 5) {
    printf("2\n2 3\n");
    return 0;
  }
  if (n == 6) {
    printf("2\n3 3\n");
    return 0;
  }
  if (n == 7) {
    printf("3\n2 2 3\n");
    return 0;
  }
  n -= 3;
  memset(isprime, -1, sizeof(isprime));
  for (int i = 2; i * i < maxn; i++) {
      if (isprime[i]) {
          for (int j = i; i * j < maxn; j++)
              isprime[i*j] = 0;
      }
  }

  for (int i = 2; i < maxn; ++ i) {
    if (isprime[i]) {
      if (isPrime(n-i)) {
        printf("3\n");
        printf("3 %d %d\n", i, n-i);
        return 0;
      }
    }
  }

  return 0;
}

