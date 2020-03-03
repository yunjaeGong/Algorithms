#include <iostream>
#include <queue>
#define f first
#define s second
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
using namespace std;
#define pii pair<int,int>
int r, c;
int sheep, wolves, res_s, res_w;
char map[251][251];
bool visited[251][251];

void dfs(int x, int y) {
    visited[x][y] = true;
    if(map[x][y] == 'v')
        wolves++;
    else if(map[x][y] == 'k')
        sheep++;
    for(int i=0;i<4;++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(visited[nx][ny] || map[nx][ny] == '#')
            continue;
        dfs(nx, ny);
    }

}
int main() {
    cin >> r >> c;
    queue<pii> Q;
    for(int i=0;i<r;++i) {
        cin >> map[i];
        for(int j=0;j<c;++j)
            if(map[i][j] == 'v' || map[i][j] == 'k')
                Q.push({i, j});
    }

    while(!Q.empty()) {
        pii cur = Q.front();
        Q.pop();
        sheep = 0, wolves = 0;
        if(visited[cur.f][cur.s])
            continue;
        dfs(cur.f, cur.s);
        if(wolves >= sheep)
            res_w += wolves;
        else
            res_s += sheep;
    }
    cout << res_s << " " << res_w;
}
