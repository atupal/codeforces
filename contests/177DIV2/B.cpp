
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[101][101];
int n,m,d;
int max;
int min;

const int maxn = 100000000;

int abs(int a){
    return a > 0 ? a : -a;
}

int f(int x) {
    int ans = 0;

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (abs(A[i][j] - x) % d) 
                return maxn;
            else
                ans += abs(A[i][j] - x) / d;

        }
    }

    return ans;
}

void solve() {
    int mid;
    int midmid;
    int o;
    int n = max - min;
    while (min < max) {
        mid = min + (max - min) / 3;
        midmid = max - (max - min) / 3;
        int f_midmid;
        int f_mid;
        while (midmid < max && (f_midmid = f(midmid)) == maxn) midmid += 1;
        while (mid > min && (f_mid = f(mid)) == maxn) mid -= 1;
        if (midmid > max)
            max = midmid;
        else if (mid < min) 
            min = mid;
        else if (f_mid > f_midmid) 
            min = mid;
        else 
            max = midmid;
        o = n;
        n = max - min;
        if (o == n) {
            int a = f(min);
            int b = f(max);
            if (a <= b && a != maxn)  
                printf("%d\n", a);
            else if (b <= a && b != maxn) 
                printf("%d\n", b);
            else 
                printf("-1\n");
            return;
        }
    }
        int a = f(mid);
        int b = f(midmid);
        if (a <= b && a != maxn)  
            printf("%d\n", a);
        else if (b <= a && b != maxn) 
            printf("%d\n", b);
        else 
            printf("-1\n");
        return;
}


int main() {
    scanf("%d %d %d", &n, &m, &d);
    int sum = 0;
    min = 100000;
    max = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            scanf("%d", &A[i][j]); 
            sum += A[i][j];
            min = A[i][j] < min ? A[i][j]: min;
            max = A[i][j] > max ? A[i][j] : max;
        }
    }
    /*
    int ans = maxn;
    for (int i = min; i <= max; ++ i) {
        int t = f(i);
        ans =  t < ans ? t : ans;
    }
    printf("%d\n", ans == maxn ? -1 : ans);
    */
    solve();

    return 0;
}


