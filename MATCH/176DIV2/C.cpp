
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int A[100100];
int v[100100];
int flag;

void dfs(int i, int x){
    if (flag) return;
    if (!A[i]) {
        A[i] = x;
        v[x] = 1;
        dfs(x, n + 1 - i);
    }
    else if(A[i] != x){
        flag = 1;
    }
}

int get(int x) {
    memset(A, 0, sizeof(A));
    memset(v, 0, sizeof(v));
    flag = 0;
   for (int i = 1; i <= n; ++i)if (!A[i]){
        for (int j = 1; j <= n; ++j) if (!v[j]) {
    memset(A, 0, sizeof(A));
    memset(v, 0, sizeof(v));
            dfs(i, j);
        }
    }
    return flag;
}

int main() {
    scanf("%d", &n);
    for (int i = 1;i  <= n; ++i)if (!get(i)){
        for (int i = 1;i <= n; ++ i)
            printf("%d ", A[i]);
        printf("\n");
        return 0;
    }
    printf("-1\n");

    return 0;
}

