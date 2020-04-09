#include <iostream>
using namespace std;
int map[20][20], D[20][20];
int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j) {
            cin >> map[i][j];
            D[i][j] = map[i][j]; // 계산된 최적경로
        }
        // k: 거쳐가는 노드
    for(int k=0;k<N;++k) {
        for(int i=0;i<N;++i) { // i: 시작, j: 끝
            for(int j=0;j<N;++j) {
                if(i == k || j == k)
                    continue;
                if (D[i][j] > D[i][k] + D[k][j]) { // i에서 j 최소거리 이상이면
                    cout << -1;
                    return 0;
                }
                if(D[i][j] == D[i][k] + D[k][j]) // 딱 최소거리이면
                    map[i][j] = 0;
            }
        }
    }
    //int MIN = 1<<30;
    int sum = 0;
    // map에는 인접한 최단 노드들의 경로만 존재!
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j) {
            if(i == j)
                continue;
            sum += map[i][j];
        }
        //MIN = min(MIN, sum);
    }
    cout << sum;
}
