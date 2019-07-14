#include <iostream>
#include <queue>
#include <cstring>

int mat [502][502];

struct Edge {int vt,w;
    bool operator<(const Edge& a) const { return w > a.w; }
    Edge() = default;
    Edge(int n, int w) : vt(n), w(w) {}
};
int N,E,Dst;
using namespace std;
void dijkstra(int d[],int s) {
    fill(d,d+N,INT32_MAX);
    priority_queue<Edge> PQ;
    d[s] = 0; // 시작 정점까지 거리 0으로
    PQ.push({s,0});
    while(!PQ.empty()) {
        Edge u = PQ.top();
        PQ.pop();
        if(d[u.vt] < u.w) continue; // 현재 u까지의 거리 u.w가 최단 거리 d[i]보다 크면 방문할 필요 없음.
        for(int i=0;i<N;i++) {
            if(mat[u.vt][i] <= 0) continue; // 경로가 없거나(0) 인접한 경로가 최단 경로(-1)이면 무시
            int nDist = mat[u.vt][i] + u.w, nVt = i;
            if(d[nVt] > nDist) {
                d[nVt] = nDist; // 인접한 정점 까지의 거리 업데이트
                PQ.push({nVt,nDist}); // 방문할 정점으로
            }
        }
    }
}
void erase(int d[]) {
    // 도착 정점부터 최단 경로들을 따라 거꾸로 올라가며 최단 경로 그래프에서 삭제(방문하지 않도록)
    queue<int> Q;
    Q.push(Dst); // 도착 정점부터
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<N;i++) {
            if(mat[i][u] > 0 && d[i] + mat[i][u] == d[u]) { // 거꾸로 올라가며 i에서 현재 방문중인 정점(u)까지의 거리가 최단 경로이면
                mat[i][u] = -1; // 최단 경로임을 표시
                Q.push(i); // 거꾸로 올라가며 위 동작 반복
            }
        }
    }
}
int main() {
    while(1) {
        scanf("%d%d",&N,&E);
        if(N+E == 0) return 0;
        int d[N], s;
        scanf("%d%d",&s,&Dst);
        for(int i=0;i<N;i++)
            memset(mat[i],0,sizeof(mat[i]));
        for(int i=0;i<E;++i) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            mat[u][v] = w;
        }
        dijkstra(d,s); // 최단 경로를 찾기 위한 탐색
        erase(d); // 최단 경로 삭제
        dijkstra(d,s); // 거의 최단 경로 탐색
        printf("%d\n",d[Dst]==INT32_MAX?-1:d[Dst]);
    }
}