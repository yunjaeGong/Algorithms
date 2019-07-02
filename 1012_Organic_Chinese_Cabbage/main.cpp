#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N,M,T,K;
int visited[50][50];
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
struct P {int x,y;};

void bfs(int x, int y);

int main() {
    int x, y, cnt;
    scanf("%d",&T);

    while(T) {
        scanf("%d%d%d",&M,&N,&K); // 가로 세로
        memset(visited,0,sizeof(visited));
        cnt=0;
        for(int i=0;i<K;++i) {
            scanf("%d%d",&x,&y);
            visited[y][x] = 1;
        }
        for(int i=0;i<N;++i) {
            for(int j=0;j<M;++j) {
                if(visited[i][j] == 1) {
                    cnt++;
                    bfs(j,i);
                }
            }
        }
        cout << cnt << endl;
        T--;
    }
}
bool bound(P a) {return a.x>=0&&a.x<M&&a.y>=0&&a.y<N;}
void bfs(int x, int y) {
    queue<P> Q;
    Q.push({x,y});
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;++i) {
            P nP = {tmp.x + dx[i],tmp.y + dy[i]};
            if(bound(nP)&&visited[nP.y][nP.x]==1) {
                visited[nP.y][nP.x] = 2;
                Q.push({nP.x,nP.y});
            }
        }
    }
}