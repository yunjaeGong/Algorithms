#include <cstdio>
#include <cstring>
bool prime[1001];
int main() {
    int n,in,cnt=0;
    memset(prime,1,1001);
    prime[1] = false;
    for(int i=2;i<1001;i++) {
        if(prime[i])
            for(int j=i*2;j<1001;j+=i)
                prime[j] = false;
    }
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&in);
        if(prime[in])
            cnt += 1;
    }
    printf("%d",cnt);
}