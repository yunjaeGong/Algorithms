#include <iostream>
#include <vector>

using namespace std;
int topological_DFS(vector<vector<int>> G, int sorted[], const int V);
int main() {
    int V, E;
    cin >> V >> E;
    int *sorted = new int[V+1];
    vector<vector<int>> G(V+1);
    for(int i=1;i<=V;++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    topological_DFS(G,sorted,V);

    for(int i=1;i<=V;++i)
        cout << sorted[i] << " ";
    return 0;
}

int dfs(vector<vector<int>> G, bool visited[], int sorted[],int V, int u) {
    static int offset = V;
    visited[u] = true;
    for(auto it = G[u].begin();it != G[u].end();++it)
        if(!visited[*it])
            dfs(G,visited,sorted,V,*it);
    // backtrack 된 위치
    sorted[offset] = u;
    offset--;
    return 0;
}

int topological_DFS(vector<vector<int>> G, int sorted[], const int V) {
    bool *visited = new bool[V+1];
    for(int i=0;i<=V;++i) {
        visited[i] = false;
    }
    for(int i=1;i<=V;++i) {
        if(!visited[i])
            dfs(G,visited,sorted,V,i);
    }
    return 0;
}

