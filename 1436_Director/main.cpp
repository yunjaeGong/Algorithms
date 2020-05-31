#include <iostream>
using namespace std;
int main() {
    int N, cnt=0, i=665;
    cin >> N;
    while(++i) {
        int tmp = i;
        while(tmp) {
            if(tmp%1000 == 666) {cnt++; break;}
            tmp/=10;
        }
        if(cnt == N) break;
    }
    cout << i;
}
