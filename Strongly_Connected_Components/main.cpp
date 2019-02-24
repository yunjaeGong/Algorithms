#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> Graph;
int dfs_num(Graph &G, bool visited[], pair<int,int> trip[], const int v) {
    static int count = 0;
    visited[v] = true;// u를 방문했다고 표시
    trip[v].first = ++count;
    for(auto it=G[v].begin();it!=G[v].end();++it) {
        int next = *it;
        if(visited[next] == false) { // 방문하지 않았으면
            dfs_num(G, visited, trip, next);
            // L[W]의 length를 구한 상태
            // next에서부터 backtrack한 상태
            trip[v].second = ++count;
        } // 다음 위치 방문
    }

    return 0;
}
int dfs_SSC(Graph &G, bool visited[], const int v, vector<int>& Vec) {
    visited[v] = true;// u를 방문했다고 표시
    Vec.push_back(v); // 그룹에 추가

    for(auto it=G[v].begin();it!=G[v].end();++it) {
        int next = *it;
        if(visited[next] == false) { // 방문하지 않았으면
            dfs_SSC(G, visited, next, Vec);
            // L[W]의 length를 구한 상태
            // next에서부터 backtrack한 상태
        } // 다음 위치 방문
    }
    return 0;
}
int main() {
    int N, M, u, v, x;
    cin >> N >> M;
    Graph G(N+1), GT(N+1);
    for(int i=0;i<M;++i) {
        cin >> u >> v;
        G[u].push_back(v);
        GT[v].push_back(u); //전치행렬
    }
    pair<int,int> *trip = new pair<int,int>[N+1];
    bool *visited = new bool[N+1];
    for(int i=0;i<=N;++i) // 초기화
        visited[i] = false;

    //번호 매기기
    dfs_num(G,visited,trip,1);

    vector<int> Vec;
    for(auto it = G.begin();it!=G.end();++it) {
        for(auto iit = it->begin();iit != it->end();++iit)
            cout << *iit << ",  ";
        cout << endl;
    }
    // 시작 위치에서 다시 시작
    for(int i=0;i<=N;++i) // 초기화
        visited[i] = false;
    int max = 1;
    dfs_SSC(GT,visited,max,Vec);
    for(int i=0;i<Vec.size();++i) {
        GT[Vec[i]].clear();
        for(auto it = Vec.begin();it!=Vec.end();++it)
            cout << *it << " ";
        cout << -1 << endl;
    }

    return 0;
}


