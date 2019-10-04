#include <cstdio>
#include <algorithm>

int main() {
    int T;
    scanf("%d",&T);
    int a[3];
    for(int i=0;i<T;++i) {
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        std::sort(a,a+3);
        printf("Case %d: %d\n",i+1,a[1]);
    }
}