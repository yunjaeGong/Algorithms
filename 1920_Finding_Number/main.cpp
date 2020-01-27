#include <iostream>
#include <set>
using namespace std;
int N, M, in;
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    set<int> S;
    for(int i=0;i<N;++i) {
        cin >> in;
        S.insert(in);
    }
    cin >> M;
    for(int i=0;i<M;++i) {
        cin >> in;
        cout << (S.find(in)!=S.end()?1:0) << '\n';
    }
}
