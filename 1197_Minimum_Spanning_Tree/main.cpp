#include<bits/stdc++.h>
using namespace std;

struct Ver { int u, v, w;
    Ver(int u, int v, int w): u(u), v(v), w(w) {}
};

bool comp(Ver &a, Ver &b) {
    return a.w<b.w;
}

int Find_Set(int *set, int x) {
    if(set[x] == x || x == 0) // root이면
        return set[x]; // 루트노드 반환
    Find_Set(set, set[x]);
}

void Union(int *set, int x, int y) {
    set[Find_Set(set,y)] = Find_Set(set,x); // x 집합의 루트가 y 집합의 루트를 가리키게 함
}

int main() {
    int V, E, u, v, w, i = 0, cnt = 0;
    cin >> V >> E;
    long sum = 0; // 가중치의 합을 저장할 변수
    vector<Ver> A; // 간선의 정보가 담긴 벡터

    int set[V+1]; // 집합을 표시할 배열 set[x]는 x노드의 부모 노드를 가리킴
    for(int i=0;i<E;++i) {
        scanf("%d %d %d",&u, &v, &w);
        A.emplace_back(u,v,w);
    }
    for(int x=0;x<=V;x++)
        set[x] = x;
    //make set

    sort(A.begin(), A.begin()+E, comp);
    while(cnt < V-1) { // 싸이클 없는 트리를 만족할 때까지
        if(Find_Set(set,A[i].u) != Find_Set(set, A[i].v)) { // 다른 집합에 속해있으면
            sum += A[i].w; // 가중치 더하기
            Union(set, A[i].u, A[i].v); // 두 집합을 하나로 합치기
            cnt++; // 실제 추가된 엣지들을 카운트
        }
        i++;
    }
    cout << sum;
    return 0;
}