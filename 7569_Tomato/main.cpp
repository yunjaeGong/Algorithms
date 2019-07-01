#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
struct P {int x,y,z;};
int dx[] = {1,0,-1,0,0,0}, dy[] = {0,1,0,-1,0,0}, dz[] = {0,0,0,0,1,-1};
int M,N,H;
int bfs();
int visited[100][100][100];
queue<P> Q;
int main() {
    int max = 1;
    scanf("%d%d%d",&M,&N,&H);
    for(int z=0;z<H;++z)
        for(int y=0;y<N;++y)
            for(int x=0;x<M;++x)
                scanf("%d",&visited[z][y][x]);

    for(int z=0;z<H;++z) {
        for (int y=0;y<N;++y) {
            for (int x=0;x<M;++x) {
                if (visited[z][y][x] == 1)
                    Q.push({x,y,z});
            }
        }
    }

    bfs();
    for(int z=0;z<H;++z) {
        for (int y=0;y<N;++y) {
            for (int x=0;x<M;++x) {
                if(visited[z][y][x] == 0) {
                    printf("-1\n");
                    return 0;
                }
                if(visited[z][y][x] > max) max = visited[z][y][x];
            }
        }
    }
    cout << max-1;
}
bool bound(P a) {return a.x>=0&&a.x<M&&a.y>=0&&a.y<N&&a.z>=0&&a.z<H;}
int bfs() {
    // int cnt = 1;
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        // ++cnt;
        // visited[tmp.z][tmp.y][tmp.x] = cnt;
        for(int i=0;i<6;++i) {
            P nP = {tmp.x + dx[i],tmp.y + dy[i],tmp.z + dz[i]};
            if(bound(nP)&&visited[nP.z][nP.y][nP.x]==0) {
                visited[nP.z][nP.y][nP.x] = visited[tmp.z][tmp.y][tmp.x]+1;
                Q.push({nP.x,nP.y,nP.z});
            }
        }
    }
    return 0;
}