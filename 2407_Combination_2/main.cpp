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

string C(int n, int m) {
    if(n == m || m == 0)
        return "1";
    if(!dp[n][m].empty())
        return dp[n][m];
    return dp[n][m] = add(C(n-1, m), C(n-1, m-1));
    }

int main() {
    cin >> N >> M;
    cout << C(N,M);
}
