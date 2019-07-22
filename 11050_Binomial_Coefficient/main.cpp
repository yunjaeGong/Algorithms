    #include <cstdio>
    long long com[1001][1001];
    int main() {
        int N,M;
        scanf("%d%d",&M,&N);
        for(int i=0;i<=N;++i)
            com[0][i] = 0;
        for(int i=0;i<=M;++i)
            com[i][0] = 1;
        for(int i=1;i<=M;++i)
            for(int j=1;j<=N;++j)
                com[i][j] = (com[i-1][j-1] + com[i-1][j])% 10007;
        printf("%lld",com[M][N]%10007);
    }