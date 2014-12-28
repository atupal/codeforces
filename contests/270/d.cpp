#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 2010;
int n;
int p[maxn][maxn];
int t[maxn][maxn];

void input() {
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            scanf("%d", &p[i][j]);
            t[i][j] = p[i][j];
        }
    }
}
