#include <cstdio>
int main() {
    int N,cnt=0,div=1,len=1;
    scanf("%d",&N);
    while((N/div)>9) {
        div*=10;
        len++;
    }
    while(1) {
        if(N/div <= 9 && N/div > 0)
            cnt += (N-div + 1) * len;
        N = div-1;
        div/=10;
        len--;
        if(N<=0) break;
    }
    printf("%d",cnt);
}