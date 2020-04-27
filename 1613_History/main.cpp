#include <iostream>
using namespace std;
int N, K, T;
int map[401][401];

int main() {
    cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
    int u, v;
    cin >> N >> K;
    for(int i=0;i<K;++i) {
        cin >> u >> v;
        map[u][v] = -1;
        map[v][u] = 1;
    }
    for(int k=1;k<=N;++k) {
        for(int i=1;i<=N;++i) {
            for(int j=1;j<=N;++j) {
                if(map[i][j] == 0) { // 경로가 없다면
                    if(map[i][k] == 1 && map[k][j] == 1) map[i][j] = 1; // 거꾸로 된 순서
                    else if(map[i][k] == -1 && map[k][j] == -1) map[i][j] = -1;
                }
            }
        }
    }
    cin >> T;
    for(int i=0;i<T;++i) {
        cin >> u >> v;
        cout << map[u][v] << '\n';
    }
}
