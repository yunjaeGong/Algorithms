#include <iostream>
#include <vector>

#define ull unsigned long long
const ull DIV = 1e9+7, MAX = 1e18;

using namespace std;
int main() {
    ull sum = 1, A, x;
    cin >> A >> x;
    vector<pair<ull, ull>> v;
    v.push_back({1, A%DIV});
    for(ull i=2;i<=MAX;i*=2)
        v.push_back({i, (v.back().second * v.back().second)%DIV});
    while(!v.empty() && x) {
        if(v.back().first <= x) {
            x -= v.back().first;
            sum = (sum* v.back().second)%DIV;
        }
        else
            v.pop_back();
    }
    cout << sum;
}
