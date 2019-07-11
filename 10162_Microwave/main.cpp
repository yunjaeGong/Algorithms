#include <cstdio>
int main() {
    int K,left;
    int a[]={300,60,10},cnt[3]={0,};
    scanf("%d",&K);
    left = K;
    if(K%10!=0) {
        printf("%d",-1);
        return 0;
    }
    for(int i=0;left>0;) {
        if(left>=a[i]) {
            cnt[i]+=left/a[i];
            left%=a[i];
        }
        else ++i;
    }
    for(int i=0;i<3;++i)
        printf("%d ",cnt[i]);
}