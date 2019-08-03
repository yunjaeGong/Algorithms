#include <cstdio>
int main() {
    int N,a,b,i=0;
    scanf("%d%d%d",&N,&a,&b);
    while(++i) {
        a = a/2 + a%2;
        b = b/2 + b%2;
        N = N/2 + N%2;
        if(a == b) {
            printf("%d",i);
            break;
        }
    }
}