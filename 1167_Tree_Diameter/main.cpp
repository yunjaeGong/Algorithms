#include <cstdio>
#include <vector>
using namespace std;
int N;
int dist[100001];
struct Edge{ int n, w; };
int max_diameter;
int dfs(vector<Edge> G[], int cur) {
    if(G[cur].size() == 0) return 0; // 부모의 Edge에 연결된 가중치
    for(Edge adj:G[cur]) {
        int tmp = dfs(G, adj.n);
        if(dist[cur] > tmp + adj.w)
            dist[cur] = tmp + adj.w;
        dist[cur] = adj.w;
    }
    // dist[i] 는 i노드를 부모로 하는 subtree의 diameter
    max_diameter = max(max_diameter, dist[cur]);
}
int main() {
    int in, cur, w;
    scanf("%d",&N);
    vector<Edge> G[N+1];
    for(int i=0;i<N;++i) {
        scanf("%d",&cur);
        while(scanf("%d",&in), in!=-1) {
            scanf("%d",&w);
            G[in].push_back({in, w});
        }
    }


}
