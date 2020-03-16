#include <cstdio>
int main() {
    int N,M;
    scanf("%d%d",&N,&M);
    bool nP[1000001]={false,true,false};
    for(int i=2;i<=M;++i) {
        int j=1;
        if(!nP[i])
            while(i*(++j)<=M)
                nP[i*j] = true;
        }
    int cur = N;
    while(cur<=M) {
        if(!nP[cur])
            printf("%d\n",cur);
        cur++;
    }

}