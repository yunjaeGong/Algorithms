#include <cstdio>
int main() {
    int N,M,i,j;
    scanf("%d%d",&N,&M);
    int a[N+1];
    a[0] = 0;
    for(int i=1;i<=N;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<N;++i)
        a[i+1] += a[i];
    while(M) {
        scanf("%d%d",&i,&j);
        printf("%d\n",a[j]-a[i-1]);
        M--;
    }
}