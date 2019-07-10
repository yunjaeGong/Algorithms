#include <iostream>
#include <queue>
#include <vector>
#define Adj_List vector<vector<int>>
using namespace std;
int N,E;
void bfs(Adj_List G, int d[]) {
    queue<int> Q;
    Q.push(1);
    d[1] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int v:G[u]) {
            if(d[v] > d[u]+1) {
                Q.push(v);
                d[v] = d[u]+1;
            }
        }
    }
}
int main() {
    scanf("%d%d",&N,&E);
    Adj_List G(N+1);
    int d[N+1],u,v,cnt=1,num,max=0;
    fill(d,d+N+1,INT32_MAX);

    for(int i=0;i<E;++i) {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs(G,d);
    // sort(d+1,d+N+1);
    for(int i=1;i<=N;++i) {
        if(d[i] != INT32_MAX && d[i] > max) {
            cnt=1;
            max = d[i];
            num = i;
        }
        else if(d[i] == max)
            ++cnt;
    }
    printf("%d %d %d",num,max,cnt);
}