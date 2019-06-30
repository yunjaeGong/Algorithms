#include <iostream>
#include <cstring>
#include <queue>
#define P struct p
using namespace std;

P {int x, y;};

int N,M;
char dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int bfs(int i,int j,char visited[][101]);

int main() {
    int K,x,y,m_x,m_y,cnt=0,area=0;
    vector<int> res;
    scanf("%d%d%d",&M,&N,&K); // m n k
    char visited[M+1][101];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<K;++i) {
        scanf("%d%d%d%d",&x,&y,&m_x,&m_y);
        for(int j=y;j<=m_y;++j)
            for(int k=x;k<=m_x;++k)
                visited[j][k] = 2;
    }

    for(int i=0;i<=M;++i) {
        for(int j=0;j<=N;++j) {
            if(visited[i][j] == 0) {
                res.push_back(bfs(i, j, visited));
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    for(auto o : res) {printf("%d ",o);}
}
bool bound(P a) { return a.x>=0&&a.x<=N&&a.y>=0&&a.y<=M; }
int bfs(int i,int j,char visited[][101]) {
    queue<P> Q;
    int A = 1;
    Q.push({i,j});
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        for(int k=0;k<4;++k) {
            P nP = {tmp.x+dx[k], tmp.y+dy[k]};
            if(bound(tmp)&&visited[nP.y][nP.x]==0) {
                visited[nP.y][nP.x] = 1; // mark as visited
                A++;
                Q.push(nP);
            }
        }

    }
    return A;
}