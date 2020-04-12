#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define pss pair<short,short>
#define py first
#define px second
using namespace std;
int H, W, visited[20][21], dists[10][10], ret = 1<<30;
;
int dx[] = {0,1,0,-1}, dy[] = {-1,0,1,0};
bool vis_dfs[11];
char map[20][21];
deque<pss> dQ;
inline bool bound(int y, int x) { return y>=0&&y<H&&x>=0&&x<W; }

void bfs(int y, int x) {
    queue<pss> Q;
    Q.push({y,x});
    visited[y][x] = 1;
    while(!Q.empty()) {
        pss cur = Q.front();
        Q.pop();
        for(int i=0;i<4;++i) {
            int nx = cur.px + dx[i], ny = cur.py + dy[i];
            if(!bound(ny,nx) || map[ny][nx] == 'x' || visited[ny][nx])
                continue;
            visited[ny][nx] = visited[cur.py][cur.px] + 1;
            Q.push({ny,nx});
        }
    }
}

void dfs(int cur, int cnt, int MIN) {
    if(cnt == dQ.size()-1) {
        ret = min(MIN, ret);
        return ;
    }
    for(int i=1;i<dQ.size();++i) {
        if(!dists[cur][i] || vis_dfs[i])
            continue;
        vis_dfs[i] = true;
        dfs(i, cnt+1, MIN + dists[cur][i]);
        vis_dfs[i] = false;
    }
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    while(cin >> W >> H) {
        if(!(H&&W)) return 0;
        dQ.clear();
        bool brk = false;
        memset(visited, 0, sizeof(visited));
        memset(dists, 0, sizeof(dists));
        memset(vis_dfs, 0, sizeof(vis_dfs));
        queue<pss> Q;
        for(int i=0;i<H;++i) {
            cin >> map[i];
            for(int j=0;j<W;++j) {
                if(map[i][j] == 'o') {
                    dQ.push_front({i,j});
                }else if(map[i][j] == '*')
                    dQ.push_back({i,j});
            }
        }
        // 모든 노드에서 모든 노드로 최단거리 구하기
        for(int i=0;i<dQ.size();++i) {
            pss cur = dQ[i];
            memset(visited, 0, sizeof(visited));
            bfs(cur.py, cur.px);
            for(int j=0;j<dQ.size();++j) {
                if(i==j) continue;
                int x = dQ[j].px, y = dQ[j].py;
                dists[i][j] = visited[y][x]-1;
                if(!visited[y][x]) {
                    cout << -1 << '\n';
                    brk = true;
                    break;
                }
            }
            if(brk) break;
        }
        if(brk) continue;

        // Backtracking으로 최단거리 탐색
        vis_dfs[0] = true;
        dfs(0,0,0);
        cout << ret << '\n';
        ret = 1<<30;
    } // end of while
}
