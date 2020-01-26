#include <cstdio>
using namespace std;

int tree[10001];
int e = 0;
void pOrder(int s, int e) {
    if(s == e) return;
    int r = s+1;
    for(; r<e && tree[r]<tree[s]; r++);
    pOrder(s+1, r);
    pOrder(r, e);
    printf("%d\n", tree[s]);
}
int main(){
    for(;scanf("%d", tree+e) > 0;e++);
    pOrder(0, e);
}