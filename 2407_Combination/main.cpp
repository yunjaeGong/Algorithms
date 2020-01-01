#include <iostream>
using namespace std;
#define ll long long
int N, M;
ll cnt;
void C(int n, int m) {
    if(n <= N  && m <= M) {
            if(m == M) {
                C(n+1, m);
                cnt++;
                return;
            }
        C(n+1, m);
        C(n+1, m+1);
    }
}
int main() {
    cin >> N >> M;
    M = (M>N/2)?(N-M):M;
    C(1,1);
    cout << cnt;
}
