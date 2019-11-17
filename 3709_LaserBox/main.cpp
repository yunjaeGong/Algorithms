#include <cstdio>

int dx[] = {1,0,-1,0}, dy[] = {0,-1,0,1};

int main() {
    int n,t,r,x,y,d=0,nx,ny;
    scanf("%d",&t);
    while(t--) {
        int map[51][51] = {0,}, chk[51][51] = {0,}, ifbrk=0;
        scanf("%d %d",&n,&r);
        for(int j=0;j<r;j++) {
            scanf("%d %d",&x,&y);
            map[x][y]=1;
        }
        scanf("%d %d",&x,&y);
        if(x < 1) d = 0;
        else if(x > n) d = 2;
        else if(y > n) d = 1;
        else d = 3;
        nx = x + dx[d], ny = y + dy[d];
        while(nx<=n&&nx&&ny<=n&&ny){
            if(chk[nx][ny]==5) { // 탈출조건
                ifbrk=1;
                break;
            }
            if(map[nx][ny]==1){
                chk[nx][ny]++;
                d++;
            }
            if(d >= 4) d = 0;
            nx += dx[d], ny += dy[d];
        }
        if(ifbrk == 0) printf("%d %d\n",nx,ny);
        else printf("0 0\n");
    }
    return 0;
}