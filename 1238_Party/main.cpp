#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define Adj_List vector<vector<Edge>>
struct Edge {int node,w;
    bool operator<(const Edge& a) const { return w > a.w; }
    Edge() = default;
    Edge(int n, int w) : node(n), w(w) {}
};
int N,E;
using namespace std;
void dijkstra(Adj_List G, int d[] ,int s) {
    priority_queue<Edge> PQ;
    fill(d,d+N+1,INT32_MAX);
    d[s] = 0;
    PQ.push({s,0});
    while(!PQ.empty()) {
        Edge u = PQ.top();
        PQ.pop();
        if(d[u.node] < u.w) continue;
        for(Edge adj : G[u.node]) {
            int nDist = adj.w + d[u.node], nNode = adj.node;
            if(d[nNode] > nDist) {
                d[nNode] = nDist;
                PQ.push({nNode,nDist});
            }
        }
    }
}
int main() {
    scanf("%d%d",&N,&E);
    int d[N+1], res[N+1];
    int dst,max = 0;
    Adj_List G(N+1);
    scanf("%d",&dst);
    for(int i=0;i<E;++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
    }
    dijkstra(G,d,dst);
    memcpy(res,d,sizeof(res));
    for(int i=1;i<=N;++i) {
        if(i!=dst) {
            dijkstra(G,d,i);
            if(max < (res[i] += d[dst]))
                max = res[i];
        }
    }
    cout << max;
}