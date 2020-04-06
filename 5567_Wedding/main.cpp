#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int visited[501];
int cnt, MAX = 1<<29;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> V[N+1];
    queue<int> Q;
    for(int i=0;i<M;++i) {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    fill(visited,visited+501,MAX);
    Q.push(1);
    visited[1] = 0;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int adj:V[cur]) {
            if(visited[cur]+1 > 2 || visited[adj] <= visited[cur]+1)
                continue;
            visited[adj] = visited[cur] + 1;
            cnt++;
            Q.push(adj);
        }
    }
    cout << cnt;
}
