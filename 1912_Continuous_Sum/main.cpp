#include <cstdio>
#include <algorithm>
int main() {
    int n;
    scanf("%d",&n);
    int  in[n], dp[n], max;
    for(int i=0;i<n;++i)
        scanf("%d",&in[i]);
    dp[0] = in[0];
    max = in[0];
    for(int i=1;i<n;++i) {
        if(dp[i-1] + in[i] > in[i]) dp[i] = dp[i-1] + in[i];
        else dp[i] = in[i];
        if(dp[i] > max) max = dp[i];
    }

    for(int i=0;i<n;++i)
        printf("%d ", dp[i]);
    printf("\n%d",max);
}