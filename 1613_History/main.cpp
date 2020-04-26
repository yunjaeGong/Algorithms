#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, K, T;
int indegree[401];
bool G[401][401];
vector<int> res;
bool visited[401], linked[401];
void topoloticalSort() {
    queue<int> Q;

    for(int i=1;i<=N;++i)
        if(linked[i] && indegree[i] == 0) {
            res.push_back(i);
            Q.push(i);
        }
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int adj=1;adj<=N;++adj) {
            if(!G[cur][adj]) continue;
            if(indegree[adj] >= 1)
                indegree[adj]--;
            if(indegree[adj] == 0) {
                Q.push(adj);
                res.push_back(adj);
            }
            G[cur][adj] = false;
            Q.push(adj);
        }
    }
}
int main() {
    int u, v;
    cin >> N >> K;
    for(int i=0;i<K;++i) {
        cin >> u >> v;
        G[u][v] = true;
        indegree[v]++;
        linked[v] = true;
        linked[u] = true;
    }
    topoloticalSort();
    cin >> T;
    for(int e:res)
        cout << e << " ";
    for(int i=0;i<T;++i) {
        cin >> u >> v;
        // res
    }


}
