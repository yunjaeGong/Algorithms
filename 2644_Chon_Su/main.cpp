#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int res[101];
bool vis[101];
int main() {
    int N, M, s, t, x, y, cnt = 0;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> s >> t >> M;
    vector<int> v[N+1];
    for (int i=0;i<M;i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int adj:v[cur]) {
            if(!vis[adj]) {
                vis[adj] = true;
                res[adj] = res[cur] + 1;
                Q.push(adj);
            }
        }
    }
    cout << ((res[t]==0)?-1:res[t]);
}
