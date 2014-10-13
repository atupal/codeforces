#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lowbit(x) (x&(-x))

typedef long long int64;
const int64 maxn = 500010;

int64 n;
int64 a[maxn];
int64 s[maxn];

void input() {
    s[0] = 0;
    scanf("%lld", &n);
    for (int64 i =1; i<= n; ++ i) {
        scanf("%lld", a+i);
        s[i] = s[i-1] + a[i];
    }
    if (s[n]%3) {
        printf("0\n");
        exit(0);
    }
}

int64 ans = 0;

void solve() {
    int x = 0,y  = 0;
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == s[n]/3) {
            x = i+1;
            break;
        }
    }
    for (int i = n; i>x; -- i) {
        if (s[n] - s[i-1] == s[n]/3) {
            y = i;
            break;
        }
    }
    if (not (x*y)) {
        printf("0\n");
        exit(0);
    }
    int64 sum = 0;
    int cnt = 0;
    for (int i = x; i < y; ++ i) {
        sum += a[i];
        if (sum==s[n]/3) {
            cnt += 1;
        }
    }
    ans = (int64) cnt * (cnt-1) / 2;
    ans = cnt;

    printf("%lld\n", ans);
}

int main() {
    input();
    solve();
    return 0;
}
