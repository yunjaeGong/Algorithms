#include <cstdio>
#include <cstring>
int dp[10] = {0}, prev[10] = {0};
const int mod = 1e9;
int main() {
    int N;
    long long sum=0;
    scanf("%d",&N);
    for(int i=1;i<10;++i)
        dp[i] = 1;
    // 길이가 2이상인 계단수는 dp를 이용한다.
    for(int i=2;i<=N;++i) {
        memcpy(prev,dp,sizeof(int)*10);
        dp[0] = prev[1]%mod; // 0, 9의 경우에는 1, 8의 경우에서 1 감소, 증가의 경우만 가능
        for(int j=1;j<=8;++j)
            dp[j] = (prev[j-1] + prev[j+1])%mod; // 나머지는 1 증감 모두 가능
        dp[9] = prev[8]%mod;
    }
    for (int i=0;i<=9;i++) sum += (dp[i]%mod);
    printf("%lld",sum%mod);
}