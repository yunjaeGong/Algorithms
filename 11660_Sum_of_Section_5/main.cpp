#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M, x1, x2, y1, y2;
    cin >> N >> M;
    int map[N][N], DP[N][N];
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cin >> map[i][j];
    for(int i=1;i<N;++i)
        DP[0][i] = DP[0][i-1] + map[0][i];
    for(int i=1;i<N;++i)
        DP[i][0] = DP[i-1][0] + map[i][0];
    for(int i=1;i<N;++i) {
        for(int j=1;j<N;++j) {
            DP[i][j] = DP[i-1][j-1] + map[i][j];
        }
    }

    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j)
            cout << DP[i][j] << " ";
        cout << '\n';
        }

    for(int i=0;i<M;++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << DP[y2][x2] - DP[y2][x1] - DP[y1][x1] + DP[y1][x1] << '\n';
    }
}
