#include <iostream>
#include <queue>

struct pos {int x, y;};
using namespace std;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
void copy_to(queue<pos> &from, queue<pos> &to) {
    while(!from.empty()) {
        to.push(from.front());
        from.pop();
    }
}

int R, C;

inline bool bound(pos p) { return p.x>=0&&p.x<C&&p.y>=0&&p.y<R; }
int main() {
    cin >> R >> C;
    char map[50][51];
    int dist[50][51];
    pos dest;

    for(int i=0;i<R;++i)
        cin >> map[i];

    queue<pos> w_Q, Q, tmp;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j) {
            dist[i][j] = INT32_MAX;
            if(map[i][j] == '*')
                w_Q.push({j, i});
            else if(map[i][j] == 'S') {
                Q.push({j, i});
                dist[i][j] = 0;
            }
            else if(map[i][j] == 'D')
                dest = {j, i};
        }

    while(!Q.empty()) {
        // water level
        while(!w_Q.empty()) {
            pos cur_w = w_Q.front();
            w_Q.pop();
            for(int i=0;i<4;++i) {
                int wn_x = cur_w.x + dx[i], wn_y = cur_w.y + dy[i];
                if(bound({wn_x, wn_y}) && map[wn_y][wn_x] == '.') {
                    tmp.push({wn_x, wn_y});
                    map[wn_y][wn_x] = '*';
                }
            }
        }
        copy_to(tmp, w_Q);
        while(!Q.empty()) {
            pos cur_p = Q.front();
            Q.pop();
            for(int i=0;i<4;++i) {
                int n_x = cur_p.x + dx[i], n_y = cur_p.y + dy[i];
                if(bound({n_x,n_y}) && (map[n_y][n_x] == '.' || map[n_y][n_x] == 'D') && dist[n_y][n_x] > (dist[cur_p.y][cur_p.x]+1)) {
                    tmp.push({n_x, n_y});
                    dist[n_y][n_x] = dist[cur_p.y][cur_p.x]+1;
                }
            }
        }
        copy_to(tmp, Q);
    }
    if(dist[dest.y][dest.x]==INT32_MAX)
        cout << "KAKTUS";
    else
        cout << dist[dest.y][dest.x];
}