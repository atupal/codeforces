
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    int sum = 0;
    int x,y;
    for (int i = 0; i < n; ++ i)  {
        scanf("%d %d", &x, &y);
        sum += y - x + 1;
    }
    if (sum % k == 0)
        printf("0\n");
    else
        printf("%d\n", k - sum % k);

    return 0;
}

