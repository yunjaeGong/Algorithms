#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define pii pair<int,int>
#define s second
#define f first
char map[102][102];
bool visited[102][102];
int r, c;
int dx[] = {0,1,1,1,0,-1,-1,-1}, dy[] = {1,1,0,-1,-1,-1,0,1};

inline bool bound(int x, int y) { return x<r&&x>=0&&y<c&&y>=0; }
void dfs(pii cur) {
    visited[cur.f][cur.s] = true;
    for(int i=0;i<8;++i) {
        int nx = cur.f + dx[i], ny = cur.s + dy[i];
        if(!bound(nx, ny) || visited[nx][ny] || map[nx][ny]!='@')
            continue;
        dfs(make_pair(nx,ny));
    }
}

int main() {
    int cnt = 0;
    while(scanf("%d%d",&r,&c), r && c) {
        memset(visited, 0, sizeof(visited));
        cnt=0;
        queue<pii> Q;
        for(int i=0;i<r;++i) {
            scanf("%s", map[i]);
            for(int j=0;j<c;++j)
                if(map[i][j] == '@')
                    Q.push({i, j});
        }

        while(!Q.empty()) {
            pii cur = Q.front();
            Q.pop();
            if(visited[cur.f][cur.s])
                continue;
            dfs(cur);
            cnt++;
        }
        printf("%d\n",cnt);
    }

}

