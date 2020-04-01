#include <iostream>
#include <vector>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
int dp[100][100001];
int main() {
    int N, K, W, V;
    cin >> N >> K;
    vector<pii> items;
    for(int i=0;i<N;++i) {
        cin >> W >> V;
        items.emplace_back(W, V);
    }
    for(int i=0;i<N;++i) {
        for(int j=1;j<=K;j++) {
            if(i == 0) {
                if(items[i].f <= j)
                    dp[i][j] = items[i].s;
                continue;
            }
            if(items[i].f <= j)
                dp[i][j] = max(dp[i-1][j], items[i].s + dp[i-1][j-items[i].f]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[N-1][K];
}
