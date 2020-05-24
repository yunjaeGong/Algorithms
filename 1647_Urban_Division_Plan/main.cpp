/*#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
struct Edge {int w, u;};
bool visited[100001];
class comp {
public:
    bool operator() (Edge &a, Edge &b) { return a.w > b.w; }
};
vector<Edge> vec[100001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0;i<M;++i) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({w,v});
        vec[v].push_back({w,u});
    }
    priority_queue<Edge, vector<Edge>, comp> pq;
    int cost = 0, cnt=0;
    pq.push({0,1});
    while (!pq.empty()) {
        Edge adj = pq.top();
        pq.pop();
        if(visited[adj.u]) continue;
        visited[adj.u] = true;
        cnt++; // 방문한 정점들 카운트
        if(cnt == N) break;
        cost += adj.w;
        for(auto e:vec[adj.u]) { // 현재
            pq.push({e.w,e.u});
        }
    }
    cout << cost;
}*/

#include <cstdio>
#include <algorithm>
#include <vector>

struct Edge {int u,v,w;
    Edge()=default;
    Edge(int u,int v,int w):u(u),v(v),w(w){};
    bool operator<(const Edge& a) const
    { return this->w < a.w; }
};
int N,K;
using namespace std;
int parent[100001]; // 정점은 1번부터 시작

int find(int cur) {
    if (cur == parent[cur]) return cur;
    return parent[cur] = find(parent[cur]);
}

void make_union(int u, int v) { // 두 정점을 같은 집합에 추가(edge 추가)
    int p_u, p_v;
    p_u = find(u);
    p_v = find(v);
    parent[p_v] = p_u;
}

int main() {
    scanf("%d%d",&N,&K);

    vector<Edge> G;

    for(int i=0;i<K;++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G.push_back({u,v,w});
    }
    sort(G.begin(),G.end()); // 오름차순으로 정렬
    int sum = 0, cnt = 0;
    for(int i=0;i<=N;i++) { parent[i] = i; }
    for(int i=0;i<G.size();i++){
        // Edge의 개수가 n-1개면 MST 완성
        if(find(G[i].u) != find(G[i].v)) { // 서로 다른 집합이면
            make_union(G[i].u,G[i].v); // 두 집합 합치기(edge 생성)
            cnt++;
            if(cnt == N-1) break;
            sum += G[i].w;
        }
    }
    printf("%d",sum);
}