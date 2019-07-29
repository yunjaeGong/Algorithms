#include <cstdio>
#include <cstring>
int main() {
    char a[100][100] = {0,};
    short T,x,y,A=0;
    scanf("%hd",&T);
    while(T) {
        scanf("%hd%hd",&x,&y);
        for(int i=9;i>=0;--i)
            memset(&a[y+i][x],1,10);
        T--;
    }
    for(int i=0;i<100;++i)
        for(int j=0;j<100;++j)
            A+=a[i][j];
    printf("%hd",A);
}
