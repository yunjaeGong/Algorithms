#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int N;
struct Edge{ int n, w; };
int far_n, far_dist;
int dist[100001];
void bfs(vector<Edge> G[], int s) {
    bool visited[100001];
    memset(visited,0,sizeof(visited));
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    while(!Q.empty()) {
        int cur = Q.front();
        visited[cur] = true;
        Q.pop();
        for(Edge adj:G[cur]) {
            if(visited[adj.n]) continue;
            dist[adj.n] = dist[cur] + adj.w;
            Q.push(adj.n);
            if(dist[adj.n] > far_dist) {
                far_dist = dist[adj.n];
                far_n = adj.n;
            }
        }
    }
}
int main() {
    int in, cur, w;
    scanf("%d",&N);
    vector<Edge> G[N+1];
    for(int i=0;i<N;++i) {
        scanf("%d",&cur);
        while(scanf("%d",&in), in!=-1) {
            scanf("%d",&w);
            G[cur].push_back({in, w});
        }
    }
    // fill(dist, dist+100001, -1);
    bfs(G, 1);
    far_dist = 0;
    memset(dist,0,sizeof(dist));
    bfs(G, far_n);
    printf("%d",far_dist);
}
