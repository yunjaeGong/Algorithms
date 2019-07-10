#include <cstdio>
int main() {
    int N,K,left,cnt=0;
    scanf("%d%d",&N,&K);
    int a[N];
    left=K;
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    for(int i=N-1;left>0;) {
        if(left>=a[i]) {
            cnt+=left/a[i];
            left%=a[i];
        }
        else i--;
    }
    printf("%d",cnt);
}