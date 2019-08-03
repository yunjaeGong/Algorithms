#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
int N,Ed;
using namespace std;
int bfs(vector<int> G[], bool visited[]) {
    std::queue<int> Q;
    int cnt=0;
    Q.push(1);
    visited[1] = true;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(auto i:G[cur])
            if(!visited[i]) {
                Q.push(i);
                visited[i] = true;
                cnt++;
            }
    }
    return cnt;
}
int main() {
    int u,v;
    scanf("%d%d",&N,&Ed);
    vector<int> G[N+1];
    bool visited[N+1];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<Ed;++i) {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    printf("%d",bfs(G,visited));
}