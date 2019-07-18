#include <cstdio>

unsigned long long dp[2][93];

int main() {
    int n;
    scanf("%d",&n);
    dp[0][1] = 0, dp[1][1] = 1;

    for(int i=2;i<=n+1;++i) {
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[0][i-1];
    }
    printf("%lld",dp[0][n+1]);
}