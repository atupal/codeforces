
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[300002];
int n;

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) 
        scanf("%d", &A[i]);

    qsort(A, n, sizeof(int), cmp);
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        ans += i - A[i - 1] > 0 ? i - A[i - 1] : A[i - 1] - i;
    }

    printf("%d\n", ans);

    return 0;
}

