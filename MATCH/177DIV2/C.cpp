

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    if (k > n) 
        printf("-1\n");
    else if (n == 1) 
        printf("a\n");
    else if (k == 1)
    {
        printf("-1\n");
    }
    else if (k == 2) {
        for (int i = 0; i < n; ++ i) {
            if (i % 2) 
                printf("b");
            else
                printf("a");
        }
        printf("\n");
    }
    else{
        for (int i = 0; i < n - (k - 2); ++ i) {
            if (i % 2) 
                printf("b");
            else
                printf("a");
        }
        for (int i = 0; i < k - 2; ++ i) 
            printf("%c", 'c' + i);
        printf("\n");
    }

    return 0;
}

