#include <iostream>
#define pii pair<int,int>
using namespace std;

int main() {
    cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    pii s[N+2];
    int dp[N+2], Max = 0;
    fill(dp, dp+N+2, 0);
    for (int i=1; i<=N; i++)
        cin >> s[i].first >> s[i].second;

    for (int i=1; i<=N; i++) {
        if(i+s[i].first <= N+1) {
            dp[i+s[i].first] = max(dp[i+s[i].first], dp[i] + s[i].second);
        }
        Max = max(Max, dp[i]);
        dp[i+1] = max(dp[i+1], Max);
    }
    cout << dp[N+1];
}