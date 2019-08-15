#include <cstdio>
#include <vector>
using namespace std;
#define vi vector<int>
#define pb push_back

bool FindPath(vi tree[], vi &p,int cur, int prev, int dest) {
    p.pb(cur);
    if(cur == dest)
        return true;
    for(auto v:tree[cur]) {
        if(prev == v) continue;
        if(v == dest) // 이 조건문 지우면 완전한 경로(dest를 포함하는) 출력 가능
            return true;
        if(FindPath(tree, p,v,cur,dest)) return true;
        p.pop_back();
    }
    return false;
}

int FindLCA(vi tree[],int n1, int n2) { // FindPath 2회 호출
    int i=0;
    if (n1 == n2)
        return n1;

    vi p1, p2; // 경로를 저장할 벡터

    if(!FindPath(tree, p1, 1, 0, n1) || !FindPath(tree, p2, 1, 0, n2)) return -1;
    // 목표 정점이 존재하지 않으면 -1 반환

    /*for(int e:p1)
        printf("%d ",e);
    printf("\n");
    for(int e:p2)
        printf("%d ",e);
    printf("\n");*/

    for(;i<p1.size() && i<p2.size();++i) { // 공통 조상 탐색(루트부터)
        if(p1[i] != p2[i]) // 달라지면 이전 정점이 공통조상
            break;
    }
    return p1[i-1];
}

int FindLCA_2(vi tree[], int n1,int n2) { //
    // ?
}

int main() {
    int N,u,v,n1,n2;
    scanf("%d",&N);
    vi tree[N];
    for(int i=0;i<N-1;++i) { // 트리 생성
        scanf("%d%d",&u,&v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    scanf("%d%d",&n1,&n2);
    printf("%d",FindLCA(tree, n1, n2));
}