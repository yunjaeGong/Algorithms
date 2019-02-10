#include <iostream>
#include <queue>
using namespace std;
int main() {
    //맨 앞, 뒤만 중요.
    int n, W, L, i=0, prev;
    short val;
    cin >> n >> L >> W;
    queue<short> Q;
    for(int j=0;j<n;j++) {
        cin >> val;
        Q.push(val);
    }
    while(!Q.empty()) {

    }
    cout << ++i;
}