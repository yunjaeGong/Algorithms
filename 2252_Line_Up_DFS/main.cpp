#include <iostream>
#include <vector>
#include <queue>
using namespace std;
short indegree[32001];
bool visited[32001];
int N, M, u, v;
vector<int> res;
void topological(vector<int> map[], int cur) {
    visited[cur] = true;
    res.push_back(cur);
    for(int i=0;i<map[cur].size();++i) {
        int next = map[cur][i];
        indegree[next]--;
        if(indegree[next] == 0 && !visited[next])
            topological(map, next);
    }
}
int main() {
    cin.tie(NULL);ios_base::sync_with_stdio(false);
    cin >> N >> M;
    vector<int> map[N+1];
    for(int i=0;i<M;++i) {
        cin >> u >> v;
        map[u].push_back(v);
        indegree[v]++;
    }
    for(int i=1;i<=N;++i)
        if(indegree[i] == 0 && !visited[i])
            topological(map, i);
    for(int e:res)
        cout << e << " ";
}
