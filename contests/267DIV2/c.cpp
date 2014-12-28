#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[5010][5010], sum[5010];
int a[5010];

const long long Inf = 1LL << 60;

int main() {
    int n, m, K;
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }
    sum[0] = a[0];
    for (int i = 1; i < n; i ++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 0; i <= K; i ++) {
        dp[0][i] = -Inf;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= K && j <= (i + 1) / m; j ++) {
            dp[i + 1][j] = dp[i][j];
            if (j) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1 - m][j - 1] + sum[i] - (i - m >= 0 ? sum[i - m] : 0));
            }
        }
    }
    printf("%I64d\n", dp[n][K]);
    return 0;
}
