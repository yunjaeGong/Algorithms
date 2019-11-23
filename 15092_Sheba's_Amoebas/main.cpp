#include <cstdio>
int N, M;
int dx[] = {0,1,1,1,0,-1,-1,-1}, dy[] = {1,1,0,-1,-1,-1,0,1};
char map[102][102];
bool visited[102][102];

int dfs(int y, int x) {
    visited[y][x] = true;
    for(int i=0;i<8;++i) {
        int n_x = x+dx[i], n_y = y+dy[i];
        if(n_x > -1&&n_x < N&&n_y>-1&&n_y<M)
            if(!visited[n_y][n_x] && map[n_y][n_x]=='#')
                dfs(n_y,n_x);
    }
    return 0;
}

int main() {
    int cnt = 0;
    scanf("%d%d",&M,&N);
    for(int i=0;i<M;++i) {
        scanf("%s",map[i]);
    }
        for(int i=0;i<M;++i) {
            for(int j=0;j<N;++j) {
                if(!visited[i][j] && map[i][j]=='#') {
                    cnt++;
                    visited[i][j] = true;
                    dfs(i,j);
                }
            }
        }
    printf("%d",cnt);
}