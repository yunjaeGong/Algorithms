#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define Adj_List vector<vector<int>>
using namespace std;
bool visited[1001];
vector<int> adj[1002];
int N,M,V;

void dfs(int u) {
    visited[u]  = true;
    printf("%d ",u);
    for(int v:adj[u]) {
        if(!visited[v])
            dfs(v);
    }
}

void bfs(int u) {
    queue<int> Q;
    Q.push(u);
    visited[u]=true;
    printf("%d ",u);
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for(int n:adj[v]) {
            if(visited[n])
                continue;
            visited[n]=true;
            Q.push(n);
            printf("%d ",n);
        }
    }
}

int main() {
    int u,v;
    scanf("%d%d%d",&N,&M,&V);
    for(int i=0;i<M;++i) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=N;++i)
        sort(adj[i].begin(),adj[i].end());
    dfs(V);
    memset(visited,0,N+1);
    printf("\n");
    bfs(V);
}
