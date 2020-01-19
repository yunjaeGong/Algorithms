#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;

int N;
bool visited[MAX];
int parent[MAX];
vector<int> G[MAX];

void DFS(int cur) {
    visited[cur] = true;
    for(auto next : G[cur])
        if (!visited[next]) {
            parent[next] = cur;
            DFS(next);
        }
}

int main() {
    scanf("%d",&N);
    for (int i=0;i<N-1;i++) {
        int u, v;
        scanf("%d%d",&u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1);
    for(int i=2;i<=N;++i)
        printf("%d\n", parent[i]);
}