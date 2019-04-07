#include <iostream>
#include <vector>
using namespace std;

struct V { int u, v;
    V(int u, int v): u(u), v(v) {}
};

int Find_Set(int *set, int x) {
    if(set[x] == x || x == 0) // if root
        return set[x]; // return num of root node
    Find_Set(set, set[x]); // find root of x's parent node
}

void Union(int *set, int x, int y) {
    /*
     * 한 set의 root가 다른 set의 leaf가 아닌 root를 가리키게 한다.
     * 트리의 높이를 줄인다. -> Find_Set의 재귀 호출 횟수를 줄임.
     */
    set[Find_Set(set,y)] = Find_Set(set,x); // y 원소를 포함하는 집합의 루트가 x 집합의 루트를 가리키게 함
}


int main() {
    /*
     * Disjoint set implemented with tree structure
     */
    int E; // num of elements
    cin >> E;
    int set[E+1]; // 집합을 표시할 배열 set[x], set[x]는 부모 노드를 가리킴(저장)
    vector<V> A; // 간선의 정보가 담긴 벡터
    // node num starts from 1
    for(int i=0, u, v;i<E;++i) {
        scanf("%d %d %d",&u, &v);
        A.emplace_back(u,v);
    }
    return 0;
}