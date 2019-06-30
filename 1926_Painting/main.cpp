#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#define P struct p
using namespace std;
P {int x, y;};
int N,M;
char dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int bfs(int x,int y,char visited[500][500]);
int main() {
    int cnt=0, max=0;

    scanf("%d%d",&N,&M); // 가로 세로
    char visited[500][500];
    char in[M];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            scanf("%d",&visited[i][j]);

    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            if(visited[i][j] == 1) {
                int tmp = bfs(j,i, visited);
                if(max<tmp) max = tmp;
                cnt++;
            }

    printf("%d\n%d",cnt,max);
}

bool bound(P a) { return a.x>=0&&a.x<M&&a.y>=0&&a.y<N; }

int bfs(int x,int y,char visited[500][500]) {
    queue<P> Q;
    int A = 1;
    Q.push({x,y});
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        visited[tmp.y][tmp.x] = 2;
        for(int k=0;k<4;++k) {
            P nP = {tmp.x+dx[k], tmp.y+dy[k]};
            if(bound(nP)&&visited[nP.y][nP.x]==1) {
                A++;
                visited[nP.y][nP.x] = 2;
                Q.push(nP);
            }
        }
    }
    return A;
}

