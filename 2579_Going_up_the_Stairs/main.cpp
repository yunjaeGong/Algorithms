#include <cstdio>
int dp[301];
int stairs[301];
int max(int a, int b) {return a>b?a:b;}
int main() {
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d",&stairs[i]);
    dp[0] = 0,dp[1] = stairs[1],dp[2]=dp[1]+stairs[2];
    for(int i=3;i<=N;++i) {
        dp[i] = max(stairs[i-1]+dp[i-3], dp[i-2]) + stairs[i];
    }
    printf("%d",dp[N]);
    return 0;
}