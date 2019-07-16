#include <cstdio>
#include <cstring>
#define maxN 246912
bool prime[maxN];
//false가 소수의 갯수
int main() {
    int in;
    memset(prime, 1, sizeof(prime));
    prime[1] = true;
    for(int i=2; i<=maxN; i++){
        if(prime[i])
            for(int j=i*2;j<=maxN;j+=i)
                prime[j] = false;
    }

    while(scanf("%d",&in),(in)) {
        int ret = 0;
        for(int i=in+1;i<=2*in;++i)
            if(prime[i])
                ret += 1;
        printf("%d\n", ret);
    }
}