#include <iostream>

using namespace std;
int T, H, W, N, f, no;
int main() {
    cin >> T;
    for(int i=0;i<T;++i) {
        cin >> H >> W >> N;
        f = (N%H == 0?H:N%H);
        no = (N%H == 0)?N/H:N/H+1;
        printf("%d%.2d\n", f, no);
    }
}
