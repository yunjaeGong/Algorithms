#include <iostream>

using namespace std;
const int MAX = INT32_MAX;
int dist[101][101], parent[101][101];
int main() {
    int N, M, u, v;
    cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0;i<M;++i) {
        fill(dist[i], dist[i] + N, MAX);
        cin >> u >> v;
        dist[u-1][v-1] = 1;
        parent[u-1][v-1] = u-1;
    }

    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            for(int k=0;k<N;++k) {
                if(dist[k][j] < dist[k][i] + dist[i][j]) {
                    dist[k][j] = dist[k][i] + dist[i][j];
                    parent[k][j] = parent[i][j];
                }
            }
    int min = 1<<30;
    int sum = 0, person = 1 << 30;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            sum += dist[i][j]==MAX?0:dist[i][j];
        }
        if(sum <= min) {
            if(sum == min && person > i)
                person = i;
            if(sum < min) {
                min = sum;
            }
        }
        sum = 0;
    }

    cout << person;
}