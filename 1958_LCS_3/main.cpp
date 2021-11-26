#include <iostream>
#include  <string>

using namespace std;
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    int ***dp = new int**[101];
    for(int i=0; i<=100; i++){
        dp[i] = new int*[101];
        for(int j=0; j<=100; j++){
            dp[i][j] = new int[101];
            for(int k = 0; k<=100;k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for(int i=0;i<=l1;++i)
        dp[0][i][0] = 0;
    for(int i=1;i<=l2;++i)
        dp[i][0][0] = 0;
    for(int i=1;i<=l3;++i)
        dp[0][0][i] = 0;

    for(int i=1;i<=l1;++i) {
        for(int j=1;j<=l2;++j) {
            for(int k=1;k<=l3;++k) {
                if((s1[i-1] == s2[j-1]) && (s2[j-1] == s3[k-1]))
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else {
                    /*int MAX = max(dp[i-1][j][k], dp[i][j-1][k]);
                    MAX = max(MAX, dp[i][j][k-1]);
                    dp[i][j][k] = MAX;*/
                    
                    dp[i][j][k] = max<int>({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
    }
    cout << dp[l1][l2][l3];
}
