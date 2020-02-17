#include <iostream>
using namespace std;
int main() {
    int N, M, sin, multi, res = 1 << 30;
    cin >> N >> M;
    int min_s = 1<<30, min_M = 1<<30;
    for(int i=0;i<M;++i) {
        cin >> multi >> sin;
        if(sin < min_s)
            min_s = sin;
        if(multi < min_M)
            min_M = multi;
    }
    if(min_s*N > min_M*((N/6) + (N%6?1:0)))
        res = min_M*((N/6) + (N%6?1:0));
    else
        res = min_s*N;
    if(min_M*(N/6) + min_s*(N%6) < res)
        res = min_M*(N/6) + min_s*(N%6);
    cout << res;
}