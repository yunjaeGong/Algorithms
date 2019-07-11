#include <cstdio>
#include <algorithm>
#include <cmath>
int main() {
    int N;
    long long res=0;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    std::sort(a,a+N);
    for(int i=0;i<N;++i)
        res += abs(a[i]-i-1);
    printf("%lld",res);
}