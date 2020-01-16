#include <stdio.h>
using namespace std;
short arr[8];
int N, M;
void A(int dep, int m) {
    arr[dep] = m;
    if(dep == M) {
        for(int i=1;i<=M;++i)
            printf("%hd ", arr[i]);
        printf("\n");
        return;
    }
    for(int i=m;i<=N;++i)
        A(dep+1, i);
}
int main() {
    scanf("%d%d", &N, &M);
    A(0, 1);
}