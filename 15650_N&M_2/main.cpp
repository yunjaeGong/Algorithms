#include <iostream>
using namespace std;

int N, M;
short a[9];

void C(int n, int m) {
    if(n <= N  && m <= M) {
        a[m] = n;
        if(m == M) {
            for(int i=1;i<=M;++i)
                cout << a[i] << " ";
            cout << endl;
            C(n+1, m);
            return;
        }
        C(n+1, m+1);
        C(n+1, m);
    }
}

int main() {
    cin >> N >> M;
    C(1,1);
}