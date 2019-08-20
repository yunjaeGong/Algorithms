#include <cstdio>
#include <cstring>
#include <algorithm>

const int MaxN = 26;
using namespace std;

bool dfs(int **flow, int p[], bool visited[], int s, int t, int cur) {
    // augmenting path 존재하면 true
    // 경로 존재하면 parent 추가
    if(cur == t)
        return true;
    visited[cur] = true;
    for(int i=0;i<MaxN;++i) {
        if(flow[cur][i] && !visited[i]) { // 현재 방문하는 정점에 인접한 정점이 방문 가능하면 (flow > 0)
            p[i] = cur;
            if(dfs(flow, p, visited, s, t, i))
                return true;
        }
    }
    return false;
}

int Ford_Fulkerson(int **flow, int s, int t) {
    int max_flow = 0, augmenting_flow = 1<<30;
    int parent[MaxN];
    fill(parent,parent+MaxN,-1);
    // int residual[N][N]; // ?
    bool visited[MaxN];
    memset(visited,0,sizeof(int)*MaxN);
    // memcpy(residual,flow,sizeof(int)*N*N); // ?
    while(dfs(flow, parent, visited, s, t, s)) { // s -> t augmenting path가 존재하면
        memset(visited, false, sizeof(visited));

        for(int v=t;v != s;v = parent[v]) {
            int u = parent[v];
            if(augmenting_flow > flow[u][v])
                augmenting_flow = flow[u][v];
        } // augmenting path의 최소 유량 찾기

        for(int v=t;v != s;v = parent[v]) {
            int u = parent[v]; // v의 인접(s에 가까운) 정점
            flow[u][v] -= augmenting_flow; // augmenting path의 최소 유량
            flow[v][u] += augmenting_flow; // augmenting path의 최소 유량
        } // t -> s까지 parent 배열을 통해 거꾸로 탐색하며 edge의 flow 업데이트
        max_flow += augmenting_flow;
    }

    // t->s까지
    // forward, backward edge 업데이트
    return max_flow;
}

int main() {
    int N;
    scanf("%d",&N);
    getchar();
    int *flow[MaxN];
    for(int i=0;i<MaxN;++i) {
        flow[i] = new int[MaxN];
        memset(flow[i], false, sizeof(int)*MaxN); // flow 초기값 0
    }

    for(int i=0;i<N;++i) {
        char u,v;
        int c;
        scanf("%c %c %d",&u,&v,&c);
        getchar();
        u-='A', v-='A';
        flow[u][v] = c; // 초기 유량
    }
    printf("%d",Ford_Fulkerson(flow, 0, MaxN-1));
}