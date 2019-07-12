#include <cstdio>
#include <cstring>
int T;
int main() {
    scanf("%d",&T);
    int c[]={1,2,3}, sum;
    while(T) {
        int K;
        scanf("%d",&K);
        int d[K+1];
        memset(d,0,sizeof(d));
        d[0] = 1;
        for (int j=1;j<=K;j++) {
            sum=0;
            for (int i=0;i<3;i++) {
                if (j>=c[i])
                    sum +=d[j-c[i]];
            }
            d[j] = sum;
        }
        printf("%d\n",d[K]);
        T--;
    }

}