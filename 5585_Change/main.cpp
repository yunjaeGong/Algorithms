#include <cstdio>
int main() {
    int K,left,cnt=0;
    int a[]={1,5,10,50,100,500};
    scanf("%d",&K);
    left=1000-K;
    for(int i=5;left>0;) {
        if(left>=a[i]) {
            cnt+=left/a[i];
            left%=a[i];
        }
        else i--;
    }
    printf("%d",cnt);
}