#include <cstdio>
#include <cstring>
#include <algorithm>
int N,K;
int main() {
    scanf("%d%d",&N,&K);
    int c[N],d[K+1];
    memset(d,0,sizeof(d));
    for(int i=0;i<N;++i)
        scanf("%d",&c[i]);
    d[0] = 1;
    for (int i=0;i<N;i++)
        for (int j=1;j<=K;j++)
            if (j>=c[i])
                d[j]+=d[j-c[i]];

        printf("%d",d[K]);
}