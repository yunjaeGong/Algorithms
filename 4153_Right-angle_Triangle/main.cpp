#include <cstdio>
#include <algorithm>
int main() {
    while(1) {
        int a[3];
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        if(a[0]+a[1]+a[2] == 0) break;
        std::sort(a,a+3);
        if(a[2]*a[2] == a[1]*a[1] + a[0]*a[0])
            printf("%s\n","right");
        else
            printf("%s\n","wrong");
    }
}