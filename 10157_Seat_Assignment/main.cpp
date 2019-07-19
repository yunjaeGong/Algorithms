#include <cstdio>
#include <cstring>
int dx[] = {0,1,0,-1},dy[] = {-1,0,1,0},C,R,K;
bool bound(int x, int y) {return x>=0&&x<C&&y>=0&&y<R;}
int main() {
    int d=0,i=0; // 가로 세로
    scanf("%d%d%d",&C,&R,&K);
    bool done = false;
    int x = 0,y = R-1,cnt=0,a[R][C];
    for(int k=0;k<R;++k)
        memset(a[k],0,sizeof(a[k]));
    while(!done) {
        if(bound(x + dx[d],y + dy[d]) && a[y + dy[d]][x + dx[d]] == 0) {
            cnt=0;
            a[y + dy[d]][x + dx[d]] = ++i;
            if(i == K) {
                printf("%d %d",x + dx[d]+1,R-(y + dy[d]));
                break;
            }
            if(bound(x + dx[d],y + dy[d])) x += dx[d],y += dy[d];
        }
        else if(!bound(x + dx[d],y + dy[d]) || a[y][x] != 0) {
            (++d)%=4;
            cnt++;
            if(cnt >=4) {
                done=true;
                printf("%d",0);
                break;
            }
        }
    }
}