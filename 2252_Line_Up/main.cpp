#include <iostream>
#include <vector>
#include <queue>
using namespace std;
short indegree[32001];
int N, M, u, v;
vector<int> res;
void topological(vector<int> map[]) {
    queue<short> Q;
    for(int i=1;i<=N;++i)
        if(indegree[i] == 0)
            Q.push(i);

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        res.push_back(cur);
        for(int i=0;i<map[cur].size();++i) {
            indegree[map[cur][i]]--;
            if(indegree[map[cur][i]] == 0)
                Q.push(map[cur][i]);
        }
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
    topological(map);
    for(int e:res)
        cout << e << " ";
}
