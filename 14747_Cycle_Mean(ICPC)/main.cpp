#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
struct Edge{
    int v,w;
};
struct P{
    int len,sum;
};
P min_p;
int N,E;
double g_min = 10000000.0;

void dfs(vector<Edge> Adj[], bool vis[],int s,int dest, int len, int sum) {
    for(Edge e:Adj[s]) {
        if(e.v == dest) {
            if((sum+e.w)/(double)(len+1) < g_min) {
                g_min = (sum+e.w)/(double)(len+1);
                min_p = {len+1,sum+e.w};
            }
        }
        if(vis[e.v])
            continue;
        vis[e.v] = true;
        dfs(Adj,vis,e.v,dest,len+1,sum+e.w);
        vis[e.v] = false;
    }
}
int main() {
    int u,v,w;
    scanf("%d%d",&N,&E);
    vector<Edge> Adj[N];
    bool visited[N];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<E;++i) {
        scanf("%d%d%d",&u,&v,&w);
        Adj[u].push_back({v,w});
    }
    for(int i=0;i<N;++i) {
        memset(visited,0,sizeof(visited));
        visited[i] = true;
        dfs(Adj,visited,i,i,0,0);
    }
    printf("%d %d",min_p.sum, min_p.len);
}