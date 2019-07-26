#include <cstdio>
int a[500][500],dp[500][500];
int M,N,dx[]={0,1,0,-1},dy[]={-1,0,1,0};
int cnt;
inline bool bound(int x,int y) {return x>=0&&x<N&&y>=0&&y<M;}
int dfs(int x,int y) {
    for(int i=0;i<4;++i) {
        int t_x = x+dx[i], t_y = y+dy[i];
        if(!bound(t_x,t_y)) continue;
        if(a[y][x] > a[t_y][t_x]) {
            if(t_x == N-1 && t_y == M-1) {
                cnt++; return 0;
            }
            dfs(t_x,t_y);
        }

    }
}
int main() {
    scanf("%d%d",&M,&N); // 세로, 가로
    for(int i=0;i<M;++i)
        for(int j=0;j<N;++j)
            scanf("%d",&a[i][j]);
    dfs(0,0);
    printf("%d",cnt);
}