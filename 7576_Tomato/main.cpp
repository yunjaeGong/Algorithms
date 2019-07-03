#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
struct P {int x,y;};
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
int M,N;
int visited[1000][1000];
queue<P> Q;

bool bound(P a) {return a.x>=0&&a.x<M&&a.y>=0&&a.y<N;}
int bfs() {
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;++i) {
            P nP = {tmp.x + dx[i],tmp.y + dy[i]};
            if(bound(nP)&&(visited[nP.y][nP.x]==0||visited[nP.y][nP.x]>visited[tmp.y][tmp.x]+1)) {
                    visited[nP.y][nP.x] = visited[tmp.y][tmp.x]+1;
                Q.push({nP.x,nP.y});
            }
        }
    }
    return 0;
}
int main() {
    int max = 1;
    scanf("%d%d",&M,&N);
    for(int y=0;y<N;++y)
        for(int x=0;x<M;++x)
            scanf("%d",&visited[y][x]);

    for(int y=0;y<N;++y)
        for(int x=0;x<M;++x)
            if(visited[y][x] == 1)
                Q.push({x,y});

    bfs();
    for(int y=0;y<N;++y) {
        for(int x=0;x<M;++x) {
            if(visited[y][x] == 0) {
                printf("-1");
                return 0;
            }
            if(visited[y][x] > max) max = visited[y][x];
        }
    }
    cout << max-1;
}
