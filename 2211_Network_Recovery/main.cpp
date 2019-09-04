#include <iostream>
#include <vector>
#include <queue>
#define Adj_List vector<Edge>

struct Edge {int p,cur,w;
    bool operator<(const Edge& a) const { return w > a.w; }
    Edge() = default;
    Edge(int v, int w, int p=0) : cur(v), w(w), p(p) {}
};
int N,E;
using namespace std;
vector<Edge> res;
void dijkstra(Adj_List G[], int d[] ,int s) {
    priority_queue<Edge> PQ;
    fill(d,d+N+1,INT32_MAX); // 시작 정점에서 모든 정점까지의 거리 초기화
    d[s] = 0; // 시작 정점 0으로 초기화

    PQ.push({s,0});
    while(!PQ.empty()) {
        Edge e = PQ.top();
        PQ.pop();
        if(d[e.cur] < e.w) continue;
        // 시작 정점에서 cur 정점까지 현재 edge(e)를 이용한 거리가 최단 거리가 아니면 continue

        // 부모 존재하면 res에 push
        if(e.p != 0) res.push_back(e);
        for(Edge adj : G[e.cur]) { // u에 인접한 모든 정점에 대해
            int nDist = adj.w + d[e.cur], nNode = adj.cur;
            if(d[nNode] > nDist) {
                d[nNode] = nDist;
                PQ.push({nNode,nDist,e.cur}); // 각각 다음 방문할 정점, 업데이트한 거리, 다음 방문할 정점의 부모 정점
            } // 거리 업데이트
        }
    }
}
int main() {
    scanf("%d%d",&N,&E);
    int d[N+1];
    int s;
    Adj_List G[N+1];

    for(int i=0;i<E;++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dijkstra(G,d,1);
    printf("%d\n",res.size());
    for(auto e:res)
        printf("%d %d\n",e.p,e.cur);
}