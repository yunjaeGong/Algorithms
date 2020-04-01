#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    map<string, string> m;
    int N, Q;
    string url, val;
    cin >> N >> Q;
    for(int i=0;i<N;++i) {
        cin >> url >> val;
        m.insert({url, val});
    }
    for(int i=0;i<Q;++i) {
        cin >> url;
        cout << m.find(url)->second << '\n';
    }
}