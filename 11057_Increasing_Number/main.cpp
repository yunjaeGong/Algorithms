#include <cstdio>
#include <cstring>
const int mod=10007;
int main() {
    int N, dp[10],prev[10],sum=0;
    scanf("%d",&N);
    for(int i=0;i<10;++i)
        dp[i] = 1;
    for(int i=2;i<=N;++i) {
        memcpy(prev,dp,sizeof(int)*10);
        for(int i=1;i<10;++i)
            dp[i] = (prev[i]+dp[i-1])%mod;
    }
    for(int i=0;i<10;++i)
        sum += dp[i];
    printf("%d",sum%mod);
}