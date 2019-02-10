#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;
int M, N;
pair<int,int> look[4]= { {make_pair(-1, 0)}, {make_pair(0, -1)}, {make_pair(0, 1)}, {make_pair(1, 0)} };
bool inside(pair<int,int> p) { return (p.first < M && p.first >= 0) && (p.second >= 0 && p.second < N); }

int bfs_percolable(int** matrix, int start_column) {
    queue<pair<int,int> > percolable; // 방문할 위치 저장하는 큐
    percolable.push(make_pair(0, start_column)); // 시작 위치 큐에 push
    while (!percolable.empty()) {
        pair<int, int> current = percolable.front(); // 현재 방문하는 위치 저장
        percolable.pop();

        for (int i = 0; i < 4; ++i) {
            pair<int,int> next = make_pair(current.first + look[i].first, current.second + look[i].second); // 이동 가능한 위치를 next에 저장
            if (matrix[next.first][next.second] == 0 && inside(next)) { // 다음 위치가 방문 가능하고 boundary 내이면
                matrix[next.first][next.second] = -1; // 전류가 흐른다고 표시
                if (next.first == M-1) return 1;
                percolable.push(next); // 방문할 위치로 push
            }
        }
    }
    return 0;
}

int main() {
    cin >> M >> N;
    int **Adj_matrix = new int*[M];
    for (int i=0;i<M;++i)
        Adj_matrix[i] = new int[N];

    for (int i=0;i<M;++i)
        for (int j=0;j<N;++j)
            scanf("%1d", &Adj_matrix[i][j]);

    for (int i=0;i<N;++i) {
        int val = 0;
        if (Adj_matrix[0][i] == 0)
            val = bfs_percolable(Adj_matrix, i);
        if (val == 1) {
            cout << "YES";
            return 0;
        }
    }
        cout << "NO";
        return 0;
}