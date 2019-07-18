#include <cstdio>
int set[1000001];
int Find_Set(int x) {
    if(set[x] == x) // if root
        return set[x]; // return num of root node
    return set[x] = Find_Set(set[x]); // find root of x's parent node
    // set element's root to newly found root
}

void Union(int x, int y) {
    set[Find_Set(y)] = Find_Set(x); // y's root is pointed to set x's root
    // -> y가 x 집합에 편입됨.
}

int main() {
    int N,E;
    scanf("%d%d",&N,&E);
    for(int i=0;i<=N+1;++i)
        set[i] = i;
    for(int i=0, o, u, v;i<E;++i) {
        scanf("%d%d%d",&o,&u,&v);
        if(o == 0)
            Union(u,v);
        else if(Find_Set(u) == Find_Set(v))
            printf("YES\n");
        else
            printf("NO\n");
    }
    /*
     * 0: Union u and v
     * 1: Find u and v
     */
    return 0;
}