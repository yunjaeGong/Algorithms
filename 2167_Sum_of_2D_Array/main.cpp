#include <cstdio>
int dp[301][301];
int main() {
    int N,M,K,i,j,x,y;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
            scanf("%d",&dp[i][j]);
    // 누적합 계산
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
            dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);
        // dp[i-1][j-1]이 중복됨.

    scanf("%d",&K);
    while(K) {
        scanf("%d%d%d%d",&i,&j,&x,&y);
        printf("%d\n",dp[x][y]-dp[x][j-1]-dp[i-1][y]+dp[i-1][j-1]);
        // 중복돼 빠진 dp[i-1][j-1]를 더해줌
        K--;
    }
}