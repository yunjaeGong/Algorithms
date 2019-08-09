#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int N;
struct P {int height, diameter;};
struct edge{int v, weight;};
P dfs(vector<edge> G[], P arr[], int v, bool visited[]) {
    P tmp = {0,0};
    int prev_height = 0, max_diameter =0;
    visited[v] = true;
    if(G[v].empty()) // leaf
        return {0,0};
    for(auto adj:G[v]) { // v를 포함하지 않는 최대 독립 집합 -> 자식 노드들 포함/포함x
        if(!visited[adj.v]) {
            tmp = dfs(G,arr,adj.v ,visited);
            if(arr[v].height <= tmp.height + adj.weight) {
                prev_height = arr[v].height; // 두 번째 최댓값
                arr[v].height = tmp.height + adj.weight;
            }// 포함 하는경우
            else if(prev_height < tmp.height + adj.weight)
                prev_height = tmp.height + adj.weight;
            // arr[v].height = tmp.n_inc + G[v][adj.v].weight;
            if(max_diameter < arr[adj.v].diameter) max_diameter = arr[adj.v].diameter; // subtree diameter 최대

        }
    }
    arr[v].diameter = max(arr[v].height + prev_height, max_diameter); // height 1 + height 2 or diameter
    return arr[v];
}
int main() {
    scanf("%d",&N);
    vector<edge> G[N+1];
    for(int i=0;i<N-1;++i) {
        int u, v, weight;
        scanf("%d%d%d",&u,&v,&weight);
        G[u].push_back({v,weight});
    }
    P arr[N+1];
    for(int i=1;i<=N;++i)
        arr[i] = {0,0};
    bool visited[N+1];
    memset(visited,0, sizeof(visited));
    dfs(G,arr,1,visited);
    printf("%d",max(arr[1].height, arr[1].diameter));
}