#include <cstdio>
#include <cstring>

int N,M,x,y,dir; // 0: 북, 1: 동,2: 남,3: 서
int dx[] = {0,1,0,-1}, dy[] = {-1,0,1,0};
bool bound(int X = x,int Y = y) {return X>=0&&X<M&&Y>=0&&Y<N;}
int main() {
    int cnt=0,A=0;
    scanf("%d%d%d%d%d",&N,&M,&y,&x,&dir);
    short cleaned[N][50];
    for(int i=0;i<N;++i)
        memset(cleaned,0,50);
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            scanf("%hd",&cleaned[i][j]);

    while(1) {
        cnt=0;
        if(cleaned[y][x]==0) {
            cleaned[y][x] = 2;
            A++;
        }
        for(int i=0;i<4;++i) {
            int n_d = (dir+=3)%4;
            short nx = x+dx[n_d], ny = y+dy[n_d];

            if(cleaned[ny][nx]!=0 || !bound(nx,ny))
                continue;
            x = nx, y = ny; // 청소하지 않은 공간 존재 -> 이동
            cnt = 1;
            break;
        }
        if(cnt == 1) continue;
        // 모두 청소 돼있거나 벽
        short b_d = (dir+2)%4,b_x = x+dx[b_d], b_y = y+dy[b_d];
        if(cleaned[b_y][b_x]==1 || !bound(b_x,b_y)) // 후진 불가
            break;
        x = b_x,y = b_y;
    }
    printf("%d",A);
}