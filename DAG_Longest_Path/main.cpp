#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<pair<int,int>>> &G, bool visited[], int L[], const int v, const int y, vector<int>& Vec) {
    visited[v] = true;// u를 방문했다고 표시
    if(v == y) { // y를 찾았으면 L[y] = 0으로 초기화(base case)
        L[y] = 0;
        return 0;
    }
    for(auto it=G[v].begin();it!=G[v].end();++it) {
        int next = it->first;
        if(visited[next] == false) { // 방문하지 않았으면
            dfs(G, visited, L, next, y, Vec);
            // L[W]의 length를 구한 상태
            // next에서부터 backtrack한 상태
        } // 다음 위치 방문
        if(L[next]!=-1 && L[v] < L[next]+it->second)  // 방문 된 상태면 L[next] 존재, 방문 안한 상태면 다음 위치의 L[next]를 구하고 backtrack된 후 계산
            L[v] = L[next]+it->second;
    }
    return L[v];
}
int main() {
    int N, M, u, v, w, x, y;
    cin >> N >> M;
    vector< vector<pair<int,int>> > G(N+1);
    for(int i=0;i<M;++i) {
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    cin >> x >> y;

    bool *visited = new bool[N+1];
    for(int i=0;i<=N;++i) // 초기화
        visited[i] = false;
    int *L = new int[N+1];
    for(int i=0;i<=N;++i) // 초기화
        L[i] = -1;
    vector<int> Vec;
    cout << "start vertex " << x << ": "<< dfs(G, visited, L, x, y, Vec) << endl;

    return 0;
}
