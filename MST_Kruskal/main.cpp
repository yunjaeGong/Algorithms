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

int get_parent(int parent[],int x) { // 모두 0으로 초기화
    while(parent[x] != 0) {
        if(parent[x] == x) break;
        x = parent[x];
    }
    return x;
}

void make_union(int parent[],int u, int v) { // 두 정점을 같은 집합에 추가(edge 추가)
    int p_u, p_v;
    p_u = get_parent(parent,u);
    p_v = get_parent(parent,v);
    parent[p_v] = p_u;
}

bool find_set(int parent[],int u, int v) {
    int p_u, p_v;
    p_u = get_parent(parent,u);
    p_v = get_parent(parent,v);
    if(p_u != p_v)
        return true;
    else
        return false;
}

int main() {
    scanf("%d%d",&N,&K);
    int parent[N+1]; // 정점은 1번부터 시작
    vector<Edge> G;

    for(int i=0;i<K;++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G.push_back({u,v,w});
    }
    sort(G.begin(),G.end()); // 오름차순으로 정렬
    int sum = 0;
    for(int i=0;i<=N;i++){
        parent[i] = i;
    }
    for(int i=0;i<G.size();i++){
        // Edge의 개수가 n-1개면 MST 완성
        if(find_set(parent,G[i].u,G[i].v)) { // 서로 다른 집합이면
            make_union(parent,G[i].u,G[i].v); // 두 집합 합치기(edge 생성)
            sum += G[i].w;
        }
    }
    for(int i=0;i<=N;++i)
        printf("%d ",parent[i]);
    printf("\n%d",sum);
}