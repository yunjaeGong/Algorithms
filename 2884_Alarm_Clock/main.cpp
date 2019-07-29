#include <cstdio>
const short H = 24, M=60;
int main() {
    int h,m;
    scanf("%d%d",&h,&m);
    if(m-45 < 0) h = (H+h - 1)%H;
    m = (M+m - 45)%M;
    printf("%d %d",h,m);
}