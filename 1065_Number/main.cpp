#include <stdio.h>

int main(){
    int N, a, b, c, cnt=99;
    scanf("%d", &N);
    if(N < 100) printf("%d\n",N);
    else{
        for(int i=100;i<=N;i++){
            a=i/100;
            b=(i/10)%10;
            c=i%10;
            if(a-b == b-c) cnt++;
        }
        printf("%d\n",cnt);
    }
}