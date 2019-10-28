#define ll long long
#define f0(i, n)  for(int i = 0;i < n;i++)

#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<ll> as(n, 0);
    f0(i, n)
        cin >> as[i];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            sum += as[i];
        else
            sum -= as[i];
    }
    vector<ll> res(n, 0);
    res[0] = sum;
    for (int i = 0; i < n-1; i++) {
        res[i+1] = (as[i] - res[i] / 2) * 2;
    }
    for (auto e : res) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}