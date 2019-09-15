#include <cstdio>
int N,K, cnt=0;
void Combination (int c[], int i, int n) {
    if(i<=K && n<=N) {
        c[i] = n;
        if(i == K) {
            for(int j=1;j<=K;++j)
                printf("%d ",c[j]);
            printf("\n");
            // 여기서 return하면 n을 넣지 "않는" 경우 도달 불가
            Combination(c,i,n+1); // i를 선택하지 않는 경우 호출하고
            cnt++;
            return;
        }
        Combination(c,i+1,n+1); // i를 선택하는 경우
        Combination(c,i,n+1); // i를 선택하지 않는 경우
    }
}

int nain () {
    scanf("%d%d",&N,&K);
    int c[N+1];
    Combination(c,1,1);
    printf("cnt: %d",cnt);
}