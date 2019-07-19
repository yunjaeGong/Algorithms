#include <cstdio>
int main() {
    int n;
    scanf("%d",&n);
    int c[n+1], dp[n+1];
    for(int i=1;i<=n;++i)
        scanf("%d",&dp[i]);
    dp[0] = 0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=i/2;++j) {
            if(dp[j] + dp[i-j] > dp[i])
                dp[i] = dp[j] + dp[i-j];
        }
    }
    printf("%d",dp[n]);
}