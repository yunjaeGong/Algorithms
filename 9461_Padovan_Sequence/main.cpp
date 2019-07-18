#include <cstdio>

int main() {
    int n;
    unsigned long long a[101] = {1,1,1,1,2,2};
    scanf("%d",&n);
    for(int i=6; i<=100; i++)
        a[i] = a[i-1]+a[i-5];
    while(n--){
        int t;
        scanf("%d",&t);
        printf("%lld\n",a[t]);
    }
}