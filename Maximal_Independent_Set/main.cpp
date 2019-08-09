#include <cstdio>
#include <vector>
#include <cstring>
int N;
struct P {int inc, n_inc;};
using namespace std;
P dfs(vector<int> G[], P arr[], int v, bool visited[]) {
    P tmp = {1,0};
    visited[v] = true;
    if(G[v].empty())
        return {1,0};
    for(int adj:G[v]) { // v를 포함하지 않는 최대 독립 집합 -> 자식 노드들 포함/포함x
        if(!visited[adj]) {
            tmp = dfs(G,arr,adj,visited);
            arr[v].inc += tmp.n_inc;
            arr[v].n_inc += max(tmp.n_inc, tmp.inc);
            // v를 포함하지 않는 최대 독립집합 -> 포함/포함x 경우의 최대 합
        }
    }
    return arr[v];
}

int main() {
    scanf("%d",&N);
    vector<int> G[N+1];
    for(int i=0;i<N-1;++i) {
        int u, v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        // G[v].push_back(u);
    }
    P arr[N+1];
    for(int i=1;i<=N;++i)
        arr[i] = {1,0};
    bool visited[N+1];
    memset(visited,0, sizeof(visited));
    dfs(G,arr,1,visited);
    for(int i=1;i<=N;++i) {
        printf("i: %d, inc: %d not_inc: %d\n",i, arr[i].inc, arr[i].n_inc);
    }
    printf("%d",max(arr[1].inc, arr[1].n_inc));
}