#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    int *a = (int*)malloc (sizeof(int) *n);
    int *b = (int*)malloc (sizeof(int) *n);
    for (int i = 0; i < n; ++ i) 
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++ i) 
        scanf("%d", &b[i]);

    for (int i =0; i  < m; ++ i) {
        int t, x, y, z;
        scanf("%d", &t);
        if (t == 2) {
            scanf("%d", &x);
            printf("%d\n", b[x - 1]);
        }
        else if (t == 1) {
            scanf("%d %d %d", &x, &y, &z);
            memcpy(b + y - 1, a + x - 1, sizeof(int) * z);
        }
    }

    return 0;
}
