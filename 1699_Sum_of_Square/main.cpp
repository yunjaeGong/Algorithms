#include <cstdio>
int dp[100001];
inline int min(int a, int b) {return a<b?a:b;}
int main() {
    int N;
    scanf("%d",&N);
    dp[0] = 0, dp[1] = 1;
    for(int i=2;i<=N;++i) {
        dp[i] = 1<<30;
        for (int j = 1; j*j <= i; j++)
            if(dp[i]>min(dp[i-1], dp[i - j*j]))
                dp[i] = min(dp[i-1], dp[i - j*j])+1;
    }
    printf("%d",dp[N]);
}