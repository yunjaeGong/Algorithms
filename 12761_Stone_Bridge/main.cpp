#include <iostream>
#include <queue>

using namespace std;
const int MAX = 1<<30;
int main() {
    int A, B, N, M, dist[100002];
    cin >> A >> B >> N >> M;
    fill(dist, dist+100001, MAX);
    dist[N] = 0;
    queue<int> Q;
    Q.push(N);
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        int next[] = {cur+1, cur-1, cur+A, cur+B, cur-A, cur-B, cur*A, cur*B};
        for(int i=0;i<8;++i) {
            if(next[i] < 0 || next[i] > 100000 || dist[next[i]] <= dist[cur]+1)
                continue;
            dist[next[i]] = dist[cur]+1;
            Q.push(next[i]);
        }
    }
    cout << dist[M];
}
