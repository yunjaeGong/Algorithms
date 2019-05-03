#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

/*
 * for i <- 1 to n:
 *   진입 간선이 없는 정점u를 선택
 *   A[i] = u // 정렬된 배열
 *   정점 u와 u의 진출 간선들을 모두 제거.
 *
 * O(V + E)
 * 위 시간복잡도를 위해서는 상수시간에 진입 간선이 없는 정점을 선택해야함. -> 진입분지수를 저장하는 배열 C,
 * 진입 분지수가 0인 정점들의 큐 저장.
 */

using namespace std;

int topologicalSort(vector<vector<int>>, int sorted[], int c[], const int V, const int E);
int main() {
    int V, E;
    cin >> V >> E;
    int *sorted = new int[V+1];
    int *c = new int[V+1];
    memset(c,0,V+1);
    vector<vector<int>> G(V+1);
    for(int i=1;i<=E;++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    topologicalSort(G,sorted,c,V,E);
    for(int i=1;i<=V;++i)
        cout << sorted[i] << " ";
    return 0;
}

int topologicalSort(vector<vector<int>> G, int sorted[], int c[], const int V, const int E) {
    static int offset = 1;
    queue<int> Q;
    for(int i=1;i<=V;++i) { // 진입 분지수 설정
        for(int j=0;j<G[i].size();++j) {
            int v = G[i][j];
            c[v]++;
        }
    }
    for(int i=1;i<=V;++i)
        if(c[i]==0)
            Q.push(i);

    while(!Q.empty()) {
    //for(int i=1;i<=V;++i) {
        int u = Q.front();
        Q.pop();
        for(auto it=G[u].begin();it!= G[u].end();it++) {
            // u에 인접한 정점들의 진입 분지수 배열 갱신
            if(c[*it] == 0 || --c[*it] == 0) {
                Q.push(*it);
            }
        }
        G[u].clear();
        sorted[offset] = u;
        offset++;
    }
    return 0;
}