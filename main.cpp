#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int VISITED = 0;
int N, M;
int dfs(int **Mat, int visited[], const int v) {
    int next;
    visited[v] = VISITED; // v를 방문했다고 표시
    for(int i=1;i<=N;++i) {
        if(*(Mat[v]+i) == 1) next = i; // 인접하면 next에 인접한 정점 번호
        else continue; // 인접하지 않으면 다음 정점으로 이동
        if(visited[next] != VISITED) { // v에 인접한 정점을 방문하지 않았으면
            dfs(Mat, visited, next);
        }
    }
    return 0;
}
int main() {
    int u, v;
    cin >> N >> M; // 정점, 엣지
    int **Adj = new int*[N+1]; // 인접 행렬로 구현
    for(int i=1;i<=N;++i) {
        Adj[i] = new int[N+1];
        memset(Adj[i],0,N+1);
    }
    for(int i=1;i<=M;++i) {
        scanf("%d %d",&u,&v);
        Adj[u][v] = 1; Adj[v][u] = 1; // 무향그래프
    }
    int *visited = new int[N+1];
    for(int i=0;i<=N;++i)
        visited[i]=i; // bool형이 아닌 각 정점 번호로 초기화.
    int cnt = 0; // 연결성분의 개수를 저장하는 변수
    v=1; // 1번 정점부터 탐색
    while(v <= N) {
        dfs(Adj, visited, v);
        while(visited[v] == VISITED) // 위의 깊이우선탐색에서 방문하지 않은 정점을 찾아 그 정점부터 다시 탐색
            v++;
        cnt++;
    }
    cout << cnt;
}