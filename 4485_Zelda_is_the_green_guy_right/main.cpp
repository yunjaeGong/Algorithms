#include <iostream>
#include <queue>
struct Edge {int x,y,w;
    bool operator<(const Edge& a) const { return w > a.w; }
    Edge() = default;
    Edge(int x, int y, int w) : x(x),y(y),w(w) {}
};
int N, dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
using namespace std;

bool bound(Edge a) {return a.x>=0&&a.x<N&&a.y>=0&&a.y<N;}
int bfs(int G[][125], int d[][125]) {
    priority_queue<Edge> PQ;
    d[0][0] = 0;
    PQ.push({0,0,0});
    while(!PQ.empty()) {
        Edge u = PQ.top();
        PQ.pop();
        if(d[u.y][u.x] < u.w) continue;
        for(int i=0;i<4;++i) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            Edge adj = {nx,ny,G[nx][ny] + u.w};
            if(adj.x == N-1 && adj.y == N-1)  {
                //d[ny][nx] = adj.w;
                return adj.w;
            }
            if(bound(adj)&&d[ny][nx] > adj.w) {
                d[ny][nx] = adj.w;
                PQ.push(adj);
            }
        }
    }
}

int main() {
    int G[125][125], d[125][125];
    int T = 0;
    while(1) {
        scanf("%d",&N);
        if(N==0) break;
        for(int i=0;i<N;++i) {
            for(int j=0;j<N;++j) {
                scanf("%d",&G[i][j]);
                d[i][j] = INT32_MAX;
            }
        }
        printf("Problem %d: %d\n",++T,bfs(G,d)+G[0][0]);
        /*for(int i=0;i<N;++i) {
            for(int j=0;j<N;++j) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }*/
    }
}