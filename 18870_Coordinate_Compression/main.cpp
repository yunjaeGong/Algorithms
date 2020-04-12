#include <iostream>
#include <algorithm>
using namespace std;
struct P { int v, idx, pos; };
bool cmp_1(P &a, P &b) { return a.v < b.v; }
bool cmp_2(P &a, P &b) { return a.idx < b.idx; }
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false); cout.tie(NULL);
    int N, in, ord = 1;
    cin >> N;
    struct P a[N];
    for(int i=0;i<N;++i){
        cin >> in;
        a[i] = {in, i, 0};
    }
    sort(a,a+N, cmp_1);
    a[0].pos = 0;
    for(int i=1;i<N;++i) {
        if(a[i-1].v == a[i].v)
            a[i].pos = a[i-1].pos;
        else {
            a[i].pos = ord;
            ord++;
        }
    }
    sort(a,a+N, cmp_2);
    for(P e: a)
        cout << e.pos << " ";
}
