#include <cstdio>
int max(int a, int b) {return a>b?a:b;}
int main() {
    int n;
    scanf("%d", &n);
    short W[n+1];
    int dp[n+1];
    // TODO: 초기화
    for(int i=1;i<=n;++i)
        scanf("%d", &W[i]);
        dp[0] = 0, dp[1] = W[1], dp[2] = W[1] + W[2];
    for(int i=3;i<=n;++i)
        dp[i] = max(max(dp[i-1], dp[i-2] + W[i]), dp[i-3] + W[i] + W[i-1]);
    printf("%d", dp[n]);
}