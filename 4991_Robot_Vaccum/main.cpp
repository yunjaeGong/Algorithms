#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define pss pair<short,short>
#define f first
#define s second
using namespace std;
int H, W, d_cnt, visited[20][21];
int dx[] = {0,1,0,-1}, dy[] = {-1,0,1,0};
char map[20][21];
inline bool bound(int y, int x) { return y>=0&&y<H&&x>=0&&x<W; }
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    while(cin >> W >> H) {
        int dist = 0;
        if(!(H&&W))
            return 0;
        memset(map, 0, sizeof(map));
        queue<pss> Q;
        for(int i=0;i<H;++i) {
            cin >> map[i];
            for(int j=0;j<W;++j)
                if(map[i][j] == 'o') {
                    Q.push({i,j});
                    visited[i][j] = 1;
                }

                else if(map[i][j] == '*')
                    d_cnt++;
        }
        // TODO: dirty 위치 도달 할 때마다 visited 클리어
        bool reset = false;
        while(!Q.empty()) {
            pss cur = Q.front();
            Q.pop();
            for(int i=0;i<4;++i) {
                int nx = cur.s + dx[i], ny = cur.f + dy[i];
                if(!bound(ny,nx) || map[ny][nx] == 'x' || visited[ny][nx])
                    continue;
                visited[ny][nx] = visited[cur.f][cur.s] + 1;
                if(map[ny][nx] == '*') {
                    dist += visited[ny][nx]-1;
                    memset(visited, 0, sizeof(visited));
                    visited[ny][nx] = 1; // mark as visited
                    map[ny][nx] = '.';
                    while(!Q.empty())
                        Q.pop();
                    reset = true;
                    d_cnt--;
                }
                if(d_cnt)
                    Q.push({ny,nx});
                if(reset) {
                    reset = !reset;
                    break;
                }
            }
            if(d_cnt == 0)
                break;
        }
        if(d_cnt == 0) cout << dist << '\n';
        else cout << -1 << '\n';
    } // end of while
}
