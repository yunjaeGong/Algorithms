#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

string operator+(string lstr, string rstr) {
    int sum = 0;
    string ret;
    while(!lstr.empty() || !rstr.empty() || sum) {
        if(!lstr.empty()) {
            sum += lstr.back() - '0';
            lstr.pop_back();
        }
        if(!rstr.empty()) {
            sum += rstr.back() - '0';
            rstr.pop_back();
        }
        ret.push_back((sum%10) + '0');
        sum/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string operator*(const string& str, int n) {
    return operator+(str, str); // n = 2일때만 동작
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string dp[251] = {"1", "1"};
    while(cin >> n) {
        for(int i=2;i<=n;++i) {
            dp[i] = dp[i-1] + dp[i-2]*2;
        }
        cout << dp[n] << '\n';
    }
}
