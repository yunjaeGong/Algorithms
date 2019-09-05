#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    string in;
    cin >> N >> M;
    set<string> not_heard, not_seen, res;
    for(int i=0;i<N;++i) {
        cin >> in;
        not_heard.insert(in);
    }
    for(int i=0;i<M;++i) {
        cin >> in;
        not_seen.insert(in);
    }
    auto heard = not_heard.begin();
    for(;heard != not_heard.end();++heard) {
        // auto it = lower_bound(not_seen.begin(),not_seen.end(), heard);
        auto it = not_seen.find(*heard);
        if(it != not_seen.end()) {
            res.insert(*it);
        }
    }
    cout << res.size() << '\n';
    for(auto e:res)
        cout << e << '\n';
}