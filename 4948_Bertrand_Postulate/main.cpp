#include <cstdio>
#include <math.h>
int main() {
    int n,cnt;
    while(scanf("%d",&n), (n)) {
        cnt = 0;
        for(int i=n+1;i<=2*n;++i) {
            int j=2;
            for(;j<=(int)sqrt(i);++j) {
                if(i%j==0)
                    break;
            }
            if(j==(int)sqrt(i)+1) cnt++; // 중간에 나누어 떨어지지 않으면 소수
        }
        printf("%d\n",cnt);
    }
}