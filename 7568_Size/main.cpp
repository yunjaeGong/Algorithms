#include <iostream>
using namespace std;
struct p { int w,h; };
p a[1000];
int main() {
    int N, w, h;
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> w >> h;
        a[i] = {w,h};
    }
    for(int i=0;i<N;++i) {
        int cnt=0;
        for(int j=0;j<N;++j) {
            if(a[i].w < a[j].w && a[i].h < a[j].h) {cnt++;}
        }
        cout << cnt+1 << " ";
    }
}
