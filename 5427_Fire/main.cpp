#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define pss pair<short,short>
#define f first
#define s second
static char map[1000][1001];
static int visited[1000][1000], W, H;
inline bool bound(int y, int x) { return y>=0&&y<H&&x>=0&&x<W; }
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        bool brk = false;
        cin >> W >> H;
        queue<pss> Q, F, tmp;
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<H;++i) {
            cin >> map[i];
            for(int j=0;j<W;++j) {
                if(map[i][j] == '@') {
                    Q.push({i, j});
                    map[i][j] = '.';
                    visited[i][j] = 1;
                }
                else if(map[i][j] == '*')
                    F.push({i,j});
            }
        }
        while(!Q.empty()) {
            while(!F.empty()) { // 한 step씩만
                pss cur = F.front();
                F.pop();
                for(int i=0;i<4;++i) {
                    int nx = cur.s + dx[i], ny = cur.f + dy[i];
                    if(!bound(ny,nx) || map[ny][nx] != '.') // 범위 이내이고, 불이 진행할 수 있으면
                        continue;
                    tmp.push({ny,nx});
                    map[ny][nx] = '*';
                }
            }
            while(!tmp.empty()) {
                F.push(tmp.front());
                tmp.pop();
            }

            while(!Q.empty()) { // 한 step씩만
                pss cur = Q.front();
                Q.pop();
                for(int i=0;i<4;++i) {
                    int nx = cur.s + dx[i], ny = cur.f + dy[i];
                    if(!bound(ny,nx)) { // 밖이면 break
                        cout << visited[cur.f][cur.s] << '\n';
                        brk = true;
                        break;
                    }
                    if(map[ny][nx] != '.' || visited[ny][nx]) // 방문했거나 불이거나 벽이면
                        continue;
                    tmp.push({ny,nx});
                    visited[ny][nx] = visited[cur.f][cur.s]+1;
                }
                if(brk)
                    break;
            }
            if(brk)
                break;
            while(!tmp.empty()) {
                Q.push(tmp.front());
                tmp.pop();
            }
        }
        if(!brk) // 영역 밖 도달 불가!
            cout << "IMPOSSIBLE\n";
    }
}