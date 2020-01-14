#include <cstdio>
typedef unsigned int ui;
int N;
ui min(int a, int b) { return a>b?b:a; }
int main() {
    scanf("%d", &N);
    ui dp[3][1001], Min = 1<<31;
    for(int j=1;j<=N;++j) {
        scanf("%u%u%u", &dp[0][j], &dp[1][j], &dp[2][j]);
    }
    for(int j=2;j<=N;++j) {
        dp[0][j] += min(dp[1][j-1] , dp[2][j-1]);
        dp[1][j] += min(dp[0][j-1] , dp[2][j-1]);
        dp[2][j] += min(dp[0][j-1] , dp[1][j-1]);
    }
    Min = min(min(dp[0][N], dp[1][N]), dp[2][N]);
    printf("%u", Min);
}