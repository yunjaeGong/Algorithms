#include <cstdio>
int N,K, cnt=0;
void Combination (int c[], int i, int m) {
    if(i<=K && m<=N) {
        c[i] = m;
        if(i == K) {
            for(int j=1;j<=K;++j)
                printf("%d ",c[j]);
            printf("\n");
            // 여기서 return하면 m을 넣지 않는 경우 도달 불가
            Combination(c,i,m+1); // i를 선택하지 않는 경우 호출하고
            cnt++;
            return; // 반환
        }
        Combination(c,i+1,m+1); // i를 선택하는 경우
        Combination(c,i,m+1); // i를 선택하지 않는 경우
    }
}

int main () {
    scanf("%d%d",&N,&K);
    int c[N+1];
    Combination(c,1,1);
    printf("cnt: %d",cnt);
}