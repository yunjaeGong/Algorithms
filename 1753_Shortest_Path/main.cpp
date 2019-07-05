#include <iostream>
#include <vector>
#include <queue>
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
    d[s] = 0; // 시작 정점 0으로 초기화

    PQ.push({s,0});
    while(!PQ.empty()) {
        Edge u = PQ.top();
        PQ.pop();
        if(d[u.node] < u.w) continue; // 왜?
        for(Edge adj : G[u.node]) { // u에 인접한 모든 정점에 대해
            int nDist = adj.w + d[u.node], nNode = adj.node;
            if(d[nNode] > nDist) {
                d[nNode] = nDist;
                PQ.push({nNode,nDist});
            } // 거리 업데이트
        }
    }
}
int main() {
    scanf("%d%d",&N,&E);
    int d[N+1];
    int s;
    Adj_List G(N+1);
    scanf("%d",&s);

    for(int i=0;i<E;++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
    }
    dijkstra(G,d,s);

    for(int i=1;i<=N;++i) {
        if(d[i] == INT32_MAX)
            printf("INF\n");
        else printf("%d\n",d[i]);
    }
}