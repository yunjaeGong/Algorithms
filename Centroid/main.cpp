#include <vector>
#include <cstdio>
using namespace std;
int N,centroid,sum=0;
int dfs(vector<vector<int>> G, int v, bool visited[],int T[],int P[],const int sum) {
    bool is_centriod = true;
    visited[v] = true;
    T[v] = P[v];
    for(auto a: G[v]) {
        int tmp;
        if(!visited[a]) {
            tmp = dfs(G,a,visited,T,P,sum);
            T[v] += tmp;
            if(tmp > sum/2) is_centriod = false;
        }
    }
    if(sum-T[v] <= sum/2 && is_centriod)
        centroid = v;
    return T[v];
}
int main() {
    scanf("%d",&N);
    vector<vector<int>> G(N+1);
    int P[N+1];
    for(int i=1;i<=N;++i) {
        scanf("%d",&P[i]);
        sum += P[i];
    }

    for(int i=0; i<N-1; ++i) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=N;++i) {
        printf("%d: ",i);
        for(int j=0;j<G[i].size();++j)
            printf("%d ",G[i][j]);
        printf("\n");
    }
    printf("\n");
    bool visited[N+1];
    int T[N+1];
    //for(int i=0;i<N;++i) {
    dfs(G,1,visited,T,P,sum);
    for(int i=1;i<=N;++i) {
        printf("%d ",T[i]);
    }
    printf("\n");
    printf("%d is Centroid",centroid);
}