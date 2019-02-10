#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while(T) {
        cin >> n;
        int dp[501][501];
        int* sum = new int[n+1];
        sum[0]=0;
        for(int i=1;i<=n;++i) {
            int tmp;
            scanf("%d",&tmp);
            sum[i] += (sum[i-1] + tmp);
        } // sum[i]: ~ i까지의 비용 합
        for(int d=0; d<n; d++) {
            for (int i=1,j=i+d;j<=n;i++,j=i+d) {
                int min = INT32_MAX;
                if(i==j) { dp[i][j]=0; continue; }
                for(int m=i;m<j;++m) {
                    if(dp[i][m] + dp[m+1][j]<min) // [i][k] ~ [k+1][j]까지 (i j 구간을 둘로 나누는 구간)의 최소 비용 합을 찾음
                        min = dp[i][m] + dp[m+1][j];
                }
                dp[i][j] = min + (sum[j]-sum[i-1]); // 최소 비용 합의 최소값 + i~j까지의 합
            }
        }
        printf("%d\n", dp[1][n]);
        T--;
    }
    return 0;
}