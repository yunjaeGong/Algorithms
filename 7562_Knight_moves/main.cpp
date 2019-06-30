#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct P {int x,y,n;};
short dx[] = {1,1,2,2,-1,-1,-2,-2}, dy[] = {2,-2,1,-1,2,-2,1,-1};
int N;
int bfs(int x, int y, int d_x, int d_y, int visited[300][300]);
int main() {
    int visited[300][300];
    int K;

    scanf("%d",&K);
    for(int i=0;i<K;++i) {
        int x,y,d_x,d_y;
        scanf("%d",&N);
        for(int j=0;j<N;++j)
            for(int k=0;k<N;++k)
                visited[j][k] = INT32_MAX;
        scanf("%d%d%d%d",&x,&y,&d_x,&d_y);
        visited[y][x] = 0;

        cout << bfs(x,y,d_x,d_y,visited) << endl;
    }
}
int bound(P a) {return a.x>=0&&a.x<N&&a.y>=0&&a.y<N;}
int bfs(int x, int y, int d_x, int d_y, int visited[300][300]) {
    queue<P> Q;
    P a = {x,y,0};
    Q.push(a);
    visited[a.y][a.x] = a.n;
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        if(tmp.x == d_x && tmp.y == d_y) return tmp.n;
        for(int i=0;i<8;++i) {
            P nP = {tmp.x + dx[i],tmp.y + dy[i],tmp.n+1};
            if(bound(nP)&&visited[nP.y][nP.x]>tmp.n+1) {
                visited[nP.y][nP.x] = nP.n;
                Q.push(nP);
            }
        }

    }
}