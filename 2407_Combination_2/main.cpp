#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N, M;
string dp[101][101];

string add(string a, string b) {
    string ret;
    long long sum = 0;
    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret.push_back((sum % 10) + '0');
        sum/=10; // carry 유지
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string C_recur(int n, int m) {
    if(n == m || m == 0)
        return "1";
    if(!dp[n][m].empty())
        return dp[n][m];
    return dp[n][m] = add(C_recur(n-1, m), C_recur(n-1, m-1));
}

string C_for() {
    for(int i=0;i<=N;++i)
        dp[i][0] = "1";
    for(int j=1;j<=M;++j) {
        for(int i=1;i<=N;++i){
            dp[i][j] = add(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    return dp[N][M];
}

int main() {
    cin >> N >> M;
    cout << C_recur(N, M) << endl;
    cout << C_for();
}
