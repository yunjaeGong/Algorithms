#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    string in;
    cin >> N >> M;
    set<string> not_heard, not_seen;
    vector<string> res;
    for(int i=0;i<N;++i) {
        cin >> in;
        not_heard.insert(in);
    }
    for(int i=0;i<M;++i) {
        cin >> in;
        not_seen.insert(in);
        if(not_heard.find(in) == not_heard.end()) continue;
        res.push_back(in);
    }
    sort(res.begin(),res.end());
    cout << res.size() << '\n';
    for(auto e:res)
        cout << e << '\n';
}

/*
#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string listen[n];
    string watch;
    priority_queue<string, vector<string>, greater<string>>lw;
    for(int i = 0; i < n; i++) cin >> listen[i];
    sort(listen, listen + n);
    for(int i = 0; i < m; i++){
        cin >> watch;
        auto it = lower_bound(listen, listen + n, watch);
        if(watch == *it) lw.push(watch);
    }
    cout << lw.size() << "\n";
    while(!lw.empty()){
        cout << lw.top() << "\n";
        lw.pop();
    }
}
 */