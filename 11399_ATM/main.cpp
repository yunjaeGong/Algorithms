#include <cstdio>
#include <algorithm>
int main() {
    int N, sum=0, nsum=0;
    scanf("%d",&N);
    short a[N];
    for(int i=0;i<N;++i) {
        scanf("%hd",&a[i]);
        sum+=a[i]; // 전체 합
    }
    std::sort(a,a+N); // 오름차순 정렬
    nsum += sum; // 가장 오래 걸리는 사람
    for(int i=N-1;i>0;--i)
        nsum+=(sum-=a[i]); //전체 합에서 가장 오래 걸리는(가장 맨 마지막에 인출하는)사람 앞 사람부터 첫 번째로 인출하는 사람 순으로 더함
    printf("%d",nsum);
}