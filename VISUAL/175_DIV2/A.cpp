
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - k - 1; ++ i) 
        printf("%d ", i + 1);
    for (int i = n; i >= n - k; -- i)
        printf("%d ", i);

    return 0;
}

