#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> Graph;
typedef vector<int> V;

int COUNT = 0;

int dfs_num(Graph &G, bool visited[], pair<int,int> *trip, const int v) { // 정점별 방문 순서 부여
    if(visited[v]) return 0;
    visited[v] = true;// u를 방문했다고 표시
    trip[v].first = ++COUNT;
    for(auto it=G[v].begin();it!=G[v].end();++it) {
        int next = *it;
        if(visited[next] == false) { // 방문하지 않았으면
            dfs_num(G, visited, trip, next);
            // next에서부터 backtrack한 상태
        } // 다음 위치 방문
    }
    trip[v].second = ++COUNT;
    return 0;
}

int dfs_SSC(Graph &G, bool visited[], const int v, V& Vec) { // 강연결요소의 개수와 원소를 찾음
    visited[v] = true;// u를 방문했다고 표시
    Vec.push_back(v); // 그룹에 추가

    for(auto it=G[v].begin();it!=G[v].end();++it) {
        int next = *it;
        if(visited[next] == false) { // 방문하지 않았으면
            dfs_SSC(G, visited, next, Vec);
        } // 다음 위치 방문
    }
    return 0;
}

int main() {
    int N, M, u, v;
    cin >> N >> M;
    
    Graph G(N + 1), GT(N + 1);
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        GT[v].push_back(u); //전치행렬
    }
    
    pair<int, int> *trip = new pair<int, int>[N + 1]; // 방문 순서를 저장
    for (int i = 0; i <= N; ++i) // 초기화
        trip[i] = make_pair(0, 0);
    
    bool *visited = new bool[N + 1]();

    //번호 매기기
    for (int i = 1; i <= N; ++i)
        dfs_num(G, visited, trip, i);

    V Vec;

    // 시작 위치에서 다시 시작
    for (int i = 0; i <= N; ++i) // 초기화
        visited[i] = false;
    
    int cnt = 0, Num = 0;
    Graph Ans; //답을 저장할 vector of vector
    
    while (cnt != N) { // 모든 원소를 포함할 때까지
        int max = 1;
        for (int k = 2; k <= N; ++k) // 가장 큰 순서를 가지는 정점을 찾고
            if (trip[max].second < trip[k].second)
                max = k;

        dfs_SSC(GT, visited, max, Vec); // 가장 큰 순서를 가지는 정점부터 방문한다.

        for (int i = 0; i < Vec.size(); ++i) { // 방문한 노드를 인접 리스트에서 삭제한다.
            GT[Vec[i]].clear();
            trip[Vec[i]] = {-1, -1};
            cnt++; // 정점을 삭제할 때마다
        }
        // 출력 조건 맞추기
        sort(Vec.begin(),Vec.end()); //각 강연결요소 집합의 정점들을 정점 번호대로 정렬
        Ans.push_back(Vec); // 정답 벡터에 추가
        Num++; // 강연결요소 개수 증가
        Vec.clear();
    }
    sort(Ans.begin(),Ans.end(),[](const V &a, const V &b) {
        return a[0] < b[0];
    });
    cout << Num << endl;
    for (auto it = Ans.begin(); it != Ans.end(); ++it) {
        for (auto iit = it->begin(); iit != it->end(); ++iit)
            cout << *iit << " ";
        cout << -1 << endl;
    }
    return 0;
}


