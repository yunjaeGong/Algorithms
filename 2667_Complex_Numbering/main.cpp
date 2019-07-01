#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct P {int x,y;};
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
int N;
int bfs(int x,int y,int cnt,int visited[25][25]);
int main() {
    int visited[25][25];
    vector<int> res;
    int cnt = 0;
    string in;
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> in;
        for(int j=0;j<N;++j) {
            visited[i][j] = in[j]-'0';
        }
    }

    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            if(visited[i][j] == 1) {
                ++cnt;
                res.push_back(bfs(j,i,cnt,visited));
            }
        }
    }
    sort(res.begin(),res.end());
    printf("%d\n",cnt);
    for(auto it:res)
        printf("%d\n",it);
}
bool bound(P a) {return a.x>=0&&a.x<N&&a.y>=0&&a.y<N;}
int bfs(int x,int y,int cnt,int visited[25][25]) {
    queue<P> Q;
    int A = 0;
    Q.push({x,y});
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        ++A;
        visited[tmp.y][tmp.x] = cnt+1;
        for(int i=0;i<4;++i) {
            P nP = {tmp.x + dx[i],tmp.y + dy[i]};
            if(bound(nP)&&visited[nP.y][nP.x]==1) {
                visited[nP.y][nP.x] = cnt+1;
                Q.push({nP.x,nP.y});
            }
        }
    }
    return A;
}