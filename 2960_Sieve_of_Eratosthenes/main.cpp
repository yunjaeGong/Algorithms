#include <cstdio>
// 에라토스테네스의 체
int main() {
    int cnt=0,N,K;
    scanf("%d%d",&N,&K);
    bool nP[1001]={false,}; // false로 초기화
    for(int i=2;i<=N;++i) { // 2부터 N까지
        int j=0;
        if(!nP[i]) { // i가 지워지지 않았으면(소수이면)
            while(i*(++j)<=N) { // i의 배수에 대해
                if(!nP[i*j])cnt++;
                nP[i*j] = true; // 소수가 아니라고 표시
                if(cnt == K) { // K번째로 지우는 수이면 출력
                    printf("%d",i*j);
                    break;
                }
            }
        }
    }
    // 약 20분
}