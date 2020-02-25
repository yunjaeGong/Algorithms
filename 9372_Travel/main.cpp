#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N;
int bfs(vector<int> *adj, int s) {
    queue<int> Q;
    int visited[N+1], dist = -1; // TODO: 밖으로 빼기
    fill(visited,visited+N+1, INT32_MAX);
    visited[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int v:adj[cur]) {
            if(visited[v] < visited[cur] + 1)
                continue;
            visited[v] = visited[cur] + 1;
            Q.push(v);
        }
    }
    for(int i=1;i<=N;++i) {
        dist = max(visited[i], dist);
    }
    return dist;
}
int main() {
    int T, M, u, v;

    cin >> T;

    while(T--) {
        int cnt = 0;
        cin >> N >> M;
        vector<int> adj[N+1];
        for(int i=0;i<M;++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=N;++i) {
            cnt = max(cnt, bfs(adj, i));
        }

        cout << cnt << '\n';
    }
}

/*#include <cstdio>
int N;
int main() {
    int T, M, u, v;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N, &M);
        for(int i=0;i<M;++i)
            scanf("%d%d",&u, &v);
        printf("%d\n",N-1);
    }
}*/
