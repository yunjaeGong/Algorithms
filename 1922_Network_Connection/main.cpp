#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, MAX = 1<<30;
struct Edge {int w, u;};
bool visited[1001];
class comp {
public:
    bool operator() (Edge &a, Edge &b) { return a.w > b.w; }
};
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    vector<Edge> vec[N+1];

    for(int i=0;i<M;++i) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({w,v});
        vec[v].push_back({w,u});
    }
    priority_queue<Edge, vector<Edge>, comp> pq;
    int cost = 0;
    pq.push({0,1});
    while (!pq.empty()) {
        Edge adj = pq.top();
        pq.pop();
        if(visited[adj.u]) continue;
        visited[adj.u] = true;
        cost += adj.w;
        for(auto e:vec[adj.u]) {
            pq.push({e.w,e.u});
        }
    }
    cout << cost;
}
