#include <cstdio>
struct oz {int one,zero;};
oz dp[41];
int main() {
    int T,n;
    dp[0] = {0,1};
    dp[1] = {1,0};
    for(int i=2;i<=40;++i) {
        dp[i].zero = dp[i-1].zero + dp[i-2].zero;
        dp[i].one = dp[i-1].one + dp[i-2].one;
    }
    scanf("%d",&T);
    while(T) {
        scanf("%d",&n);
        printf("%d %d\n",dp[n].zero, dp[n].one);
        T--;
    }
}