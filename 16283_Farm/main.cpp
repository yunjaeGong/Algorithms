#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, n, w;
    cin >> a >> b >> n >> w;
    int x = -1, count = 0;

    for(int i=1;i<n;++i) {
        if(a*i + b*(n-i) == w) {
            x = i;
            count++;
        }
    }
    if(x == -1||count!=1)
        cout << -1;
    else
        cout << x << " " << n-x;
    return 0;
}