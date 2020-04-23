#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
// 하이퍼튜브를 노드로 본다!
int N, M, K;
using namespace std;
vector<int> map[101001];
int visited[101001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int u;
    cin >> N >> K >> M;
    // 역의 수 N과 한 하이퍼튜브가 서로 연결하는 역의 개수 K, 하이퍼튜브의 개수 M
    for(int i=1;i<=M;++i)
        for(int j=0;j<K;++j) {
            cin >> u;
            map[100000+i].push_back(u);
            map[u].push_back(100000+i);
        }

    queue<int> Q;
    Q.push(1);
    visited[1] = 1;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int adj:map[cur]) {
            if(visited[adj]) continue;
            visited[adj] = visited[cur] + (adj>100000?0:1);
            Q.push(adj);
        }
    }
    cout << ((visited[N]==0)?-1:visited[N]);
}
