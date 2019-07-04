#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
struct P {int x,y,z,n;};
int dx[] = {1,0,-1,0,0,0}, dy[] = {0,1,0,-1,0,0}, dz[] = {0,0,0,0,1,-1};
int C,R,L;
bool visited[31][31][31];
char inp[32][32][32];

bool bound(P a) {return a.x>=0&&a.x<C&&a.y>=0&&a.y<R&&a.z>=0&&a.z<L;}
int bfs(int x,int y,int z) {
    memset(visited,false,sizeof(visited));
    queue<P> Q;
    Q.push({x,y,z,0});
    visited[z][y][x] = true;
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        for(int i=0;i<6;++i) {
            P nP = {tmp.x + dx[i],tmp.y + dy[i],tmp.z + dz[i],tmp.n+1};
            if(inp[nP.z][nP.y][nP.x]=='E') return nP.n;
            if(bound(nP)&&!visited[nP.z][nP.y][nP.x]&&inp[nP.z][nP.y][nP.x]=='.') {
                visited[nP.z][nP.y][nP.x] = true;
                Q.push({nP.x,nP.y,nP.z,nP.n});
            }
        }
    }
    return -1;
}

int main() {
    int res;
    int sx,sy,sz;
    while(1) {
        scanf("%d%d%d",&L,&R,&C);
        if(C + R + L == 0) return 0;
        for(int z=0;z<L;++z) {
            for(int y=0;y<R;++y) {
                scanf("%s",&inp[z][y][0]);
                for(int x=0;x<C;++x) {
                    if (inp[z][y][x] == 'S') {
                        sx=x; sy=y; sz=z;
                    }
                }
                getchar();
            }
            getchar();
        }
        // Starting Position S, Exit E

        if((res=bfs(sx,sy,sz))<0)
            cout << "Trapped!" << endl;
        else
            printf("Escaped in %d minute(s).\n",res);
    }
}
