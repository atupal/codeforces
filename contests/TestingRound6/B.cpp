
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 1000001 * 2;


int n,m;
int l[maxn];
int r[maxn];
int ind[maxn];
int max[maxn];
int dp[maxn];
char out[maxn];
int pre[maxn];

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int part(int left, int right) {
    int p = left; 

    for (int i = left + 1; i <= right; ++ i) {
        if (l[i] < l[left] || (l[i] == l[left] && r[i] > r[left] )) {
            swap(l[++p], l[i]);
            swap(r[p], r[i]);
            swap(ind[p], ind[i]);
        }
    }
    swap(l[left], l[p]);
    swap(r[left], r[p]);
    swap(ind[left], ind[p]);
    return p;
}

void qsort(int left, int right) {
    while (left < right) {
        int p = part(left, right);
        qsort(p + 1, right);
        right = p - 1;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d %d", &l[i], &r[i]);
        r[i] += l[i];
        ind[i] = i + 1;
    }

    qsort(0, m - 1);

#define DE
#ifdef DE
    printf("\n");
    for (int i = 0; i < m; ++ i) {
        printf("%d %d %d\n",i + 1, l[i], r[i]);
    }
    printf("\n");
#endif
    memset(out, 0, sizeof(out));
    memset(pre, 0, sizeof(pre));
    dp[0] = 1;
    max[0] = 0;
    out[ind[0]] = 1;
    for (int i = 1; i < m; ++ i) {
        pre[i]
        if (r[i] <= r[max[i - 1]]) {
            max[i] = max[i - 1];
            dp[i] = dp[i - 1];
        }
        else {
            dp[i] = dp[i - 1] + 1;
            max[i] = i;
            out[ind[i]] = 1;
        }
    }

    printf("%d\n", m - dp[m - 1]);
    for (int i = 1; i <= m; ++ i) {
        if (not out[i]) {
            printf("%d ", i);
        }
    }

    return 0;
}

