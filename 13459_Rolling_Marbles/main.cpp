#include <iostream>
#include <queue>
using namespace std;
int N, M;
char map[10][11];
bool visited[10][10][10][10]; // RB
int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
struct marble{int rr, rc, br, bc, cnt;};
inline bool bound(int r, int c) {return r>=0&&r<N&&c>=0&&c<M;}

int tilt(int &r, int &c, int d) {
    int cnt=0;
    while(bound(r+dr[d], c+dc[d]) && map[r+dr[d]][c+dc[d]] != '#' && map[r][c] != 'O') {
        r += dr[d];
        c += dc[d];
        cnt += 1;
    }
    return cnt;
}
void bfs(marble s) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    queue<marble> Q;
    Q.push(s);
    while(!Q.empty()) {
        marble cur = Q.front();
        Q.pop();
        if(cur.cnt >= 10) break;
        for(int i=0;i<4;++i) {
            int rr = cur.rr, rc = cur.rc, br = cur.br,bc = cur.bc;
            int r_mv_cnt = 0, b_mv_cnt = 0;
            r_mv_cnt = tilt(rr, rc, i); // 빨간 공
            b_mv_cnt = tilt(br, bc, i); // 파란 공 굴리기
            if(map[br][bc] == 'O') continue; // 빨간 공, 파란 공이 둘 다 떨어지면 무효
            if(map[rr][rc] == 'O') {
                cout << 1;
                return;
            }
            if(rr == br && rc == bc) { // 겹치면
                if(r_mv_cnt > b_mv_cnt) { // 빨간 구슬때문에 겹치면
                    rr-=dr[i];
                    rc-=dc[i];
                } else { // 파린 구슬때문에 겹치면
                    br-=dr[i];
                    bc-=dc[i];
                }
            }
            if(visited[rr][rc][br][bc]) continue;
            visited[rr][rc][br][bc];
            Q.push({rr,rc,br,bc,cur.cnt+1});
        }
    }
    cout << 0;
}

int main() {
    int rr, rc, br, bc;
    cin >> N >> M;
    for(int i=0;i<N;++i) {
        cin >> map[i];
        for(int j=0;j<M;++j) {
            if(map[i][j] == 'R')
                rr = i, rc = j;
            else if(map[i][j] == 'B')
                br = i, bc = j;
        }
    }
    visited[rr][rc][br][bc] = true;
    bfs({rr, rc, br, bc, 0});
}
