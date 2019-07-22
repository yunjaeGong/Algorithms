#include <cstdio>
long long com[31][31];
int main() {
    int N,M,T;
    scanf("%d",&T);
    while(T) {
        scanf("%d%d",&N,&M);
        for(int i=0;i<=N;++i)
            com[0][i] = 0;
        for(int i=0;i<=M;++i)
            com[i][0] = 1;
        for(int i=1;i<=M;++i)
            for(int j=1;j<=N;++j)
                com[i][j] = com[i-1][j-1] + com[i-1][j];
            printf("%lld\n",com[M][N]);
        T--;
    }
}