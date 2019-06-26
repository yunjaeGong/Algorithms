#include <iostream>
#include <math.h>
int main() {
    int N,K; // K는 방에 들어갈 수 있는 최대 인원
    scanf("%d%d",&N,&K);
    int g[N],s[N];
    int m[6]={0},f[6]={0},cnt = 0;
    for(int i=0;i<N;++i) {
        scanf("%d%d",&s[i],&g[i]); // 여 0, 남 1
    }
    for(int i=0;i<N;++i) { // 학년
        if(s[i] == 1)
            m[g[i]-1]++;/// i학년 남자 명수
        else
            f[g[i]-1]++;
    }
    for(int i=0;i<6;++i) {
        cnt += ceil(f[i]/(float)K);
        cnt += ceil(m[i]/(float)K);
    }
    std::cout << cnt;
}