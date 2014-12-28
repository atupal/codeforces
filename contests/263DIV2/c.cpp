#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
#include<cstdio>
#define  LL long long
#define maxn 300005
using namespace std;
char a[100][100];
LL ans;
LL in[maxn];
LL sum;
int n;

void solve() {
    for (int i = 1; i < n; i++) {
        ans += in[i];
        sum -= in[i];
        ans += sum;
    }
}

int main() {
    ans = sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &in[i]);
        sum += in[i];
    }
    sort(in + 1, in + 1 + n);
    ans = sum;
    solve();
    printf("%I64d\n", ans);

    return 0;
}

