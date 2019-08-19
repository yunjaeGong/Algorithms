#include <cstdio>
#include <vector>
#include <cstring>
#define vi vector<int>
#define pb push_back
using namespace std;
int N,M;
bool dfs() {
    // augmenting path 존재하면 true
    // 경로 존재하면 parent 추가
}

void Ford_Fulkerson() {
    int parent[N];
    fill(parent,parent+N,-1);

}

int main() {
    scanf("%d%d",&N,&M);
    int flow[N][N];
    memset(flow,0,sizeof(int)*N*N);
    vi G[N+1];
    for(int i=0;i<M;++i) {
        int u,v,c;
        scanf("%c %c %d",&u,&v,&c);
        getchar();
        u-='A', v-='A';
        G[u].pb(v);
        G[v].pb(u);
        flow[u][v] = c; // 초기 유량
    }

}