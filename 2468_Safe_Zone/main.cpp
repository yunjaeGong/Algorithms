#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int N,K;
bool visited[100][100];
int arr[100][100];
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
struct P {int x,y;};

void bfs(int x, int y);

int main() {
    int max_h=0, max = 0, cnt;
    scanf("%d",&N);

    for(int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            scanf("%d",&arr[i][j]);
            if(max_h<arr[i][j]) max_h = arr[i][j];
        }
    }

    for(K=0;K<=max_h;++K) {
        memset(visited,false,sizeof(visited));
        cnt = 0;
        for(int i=0;i<N;++i) {
            for(int j=0;j<N;++j) {
                if(arr[i][j] > K && !visited[i][j]) {
                    visited[i][j] = true;
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        if(max<cnt) max = cnt;
    }
    cout << max;

}
bool bound(P a) {return a.x>=0&&a.x<N&&a.y>=0&&a.y<N;}
void bfs(int x, int y) {
    queue<P> Q;
    Q.push({x,y});
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;++i) {
            P nP = {tmp.x + dx[i],tmp.y + dy[i]};
            if(bound(nP)&&!visited[nP.x][nP.y]&&arr[nP.x][nP.y]>K) {
                visited[nP.x][nP.y] = true;
                Q.push({nP.x,nP.y});
            }
        }
    }
}