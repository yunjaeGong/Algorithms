#include <iostream>
#include <queue>
struct Edge {int x,y,w;
    bool operator<(const Edge& a) const { return w > a.w; }
    Edge() = default;
    Edge(int x, int y, int w) : x(x),y(y),w(w) {}
};
int N,M, dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
using namespace std;

bool bound(Edge a) {return a.x>=0&&a.x<M&&a.y>=0&&a.y<N;}
int bfs(char G[][101], int d[][101]) {
    priority_queue<Edge> PQ;
    d[0][0] = 0;
    PQ.push({0,0,0});
    while(!PQ.empty()) {
        Edge u = PQ.top();
        PQ.pop();
        if(d[u.y][u.x] < u.w) continue;
        for(int i=0;i<4;++i) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            Edge adj = {nx,ny,(G[ny][nx]-'0') + u.w};
            if(adj.x == M-1 && adj.y == N-1) return adj.w;
            if(bound(adj)&&d[ny][nx] > adj.w) {
                d[ny][nx] = adj.w;
                PQ.push(adj);
            }
        }
    }
}

int main() {
    scanf("%d%d",&M,&N);
    char G[N][101];
    int d[N][101];

    for(int i=0;i<N;++i)
        scanf("%s",G[i]);

    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            d[i][j] = INT32_MAX;
    cout << bfs(G,d);
}