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
int r[3];
int main() {
    scanf("%d%d",&N,&E);
    int *d[3];
    for(int i=0;i<3;++i) {
        d[i] = new int[N+1];
    }
    Adj_List G(N+1);

    for(int i=0;i<E;++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    scanf("%d%d%d",&r[0],&r[1],&r[2]);
    int f_shortest = INT32_MAX;
    for(int k=0;k<3;++k) {
        dijkstra(G,d[k],r[k]);
    }

    for(int i=1;i<=N;++i) {
        int dist = 0;
        for(int j=0;j<3;++j) {
            if(dist < d[j][i] && d[j][i] > 0)
                dist = d[j][i];
        }
        if(f_shortest > dist)
            f_shortest = dist;
    }
    /*for(int u=0;u<3;++u) {
        for(int i=1;i<=N;++i) {
            if(d[u][i] == INT32_MAX)
                printf("INF ");
            else printf("%d ",d[u][i]);
        }
        printf("\n");
    }*/
    printf("%d",f_shortest);
}