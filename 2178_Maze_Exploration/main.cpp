#include <iostream>
#include <queue>
#define Pair pair<int,int>
using namespace std;
int M, N;
Pair look[4]= { {-1, 0}, {0, -1}, {0, 1}, {1, 0} }; // 현재 위치의 좌표에 각각 원소를 더해서 다음 위치의 좌표 표시.
bool inside(Pair &p) { return (p.first < N && p.first >= 0) && (p.second >= 0 && p.second < M); } // 위치 p가 할당한 배열 내에 있는지 확인

int bfs(int** matrix, int** L) {
    queue<Pair> Q; // 방문할 위치 저장하는 큐
    Q.push({0, 0}); // 시작 위치 큐에 push

    while (!Q.empty()) {
        Pair current = Q.front(); // 현재 방문하는 위치
        Q.pop();
        for(int i=0;i<4;++i) { // 네 방향 탐색
            Pair next = {current.first + look[i].first, current.second + look[i].second}; // 이동 가능한 위치를 next에 저장
            if (inside(next) && matrix[next.first][next.second] == 1) { // 다음 위치가 방문 가능하고 boundary 내이면
                matrix[next.first][next.second] = -1; // 방문했다 표시, 경로의 길이 증가
                if(L[next.first][next.second] > L[current.first][current.second]+1)
                    L[next.first][next.second] = L[current.first][current.second] + 1; // 현재 위치에서 방문 가능한 위치들에 현재 (0,0)에서 현재 위치까지의 거리 + 1
                Q.push(next); // 방문할 위치로 push
            }
        }
    } // end of while
    return L[N-1][M-1];
}

int main() {
    cin >> N >> M;

    int **matrix = new int*[N], **L = new int*[N];
    for (int i=0;i<N;++i) {
        matrix[i] = new int[M]; L[i] = new int[M];
    }
    // 미로를 저장할 maxtrix, 경로의 길이를 저장할 배열 L
    /*
     * 부분문제의 목적함수:    L[i][j]: (0,0)에서 [i][j]까지 경로 길이의 최소.
     * 재귀식:    L[next] = L[current] + 1    if(L[next] > L[current] + 1)   * next는 현재 위치에서 1만큼 이동한 위치이므로
     */
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j)
            L[i][j] = INT32_MAX;
        // 최솟값 비교를 위해 최댓값으로 초기화
    L[0][0] = 1; // 방문하는 위치(0,0)부터 카운트 시작
    for (int i=0;i<N;++i)
        for (int j=0;j<M;++j)
            scanf("%1d", &matrix[i][j]);
    cout << bfs(matrix, L); // 미로탐색
}