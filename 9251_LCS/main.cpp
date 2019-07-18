#include <cstdio>
#include <cstring>
inline int max(int a,int b) {return a>b?a:b;}
int dp[1001][1001];
int main() {
    char a[1001], b[1001];
    scanf("%s%s",a,b);
    int la = strlen(a),lb = strlen(b);
    for(int i=0;i<=la;++i)
        dp[0][i] = 0;
    for(int i=1;i<=lb;++i)
        dp[i][0] = 0;
    for(int i=0;i<la;++i) {
        for(int j=0;j<lb;++j) {
            if(a[i] == b[j])
                dp[i+1][j+1] = dp[i][j]+1;
            else
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
        }
    }
    printf("%d",dp[la][lb]);
}