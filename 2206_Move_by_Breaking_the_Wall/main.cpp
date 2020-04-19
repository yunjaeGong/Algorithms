#include <iostream>
#include <queue>
using namespace std;
char map[1000][1001];
int N, M;
int dist[1000][1001][2]; // 0: 벽 안부숨, 1: 벽 부순 최단거리
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
struct Pos { int x, y, f; };
bool B(int x, int y) { return x>=0&&x<M&&y>=0&&y<N; }
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0;i<N;++i)
        cin >> map[i];
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    queue<Pos> Q;
    Q.push({0,0,0});
    int res = -1;
    while(!Q.empty()) {
        Pos cur = Q.front();
        int x = cur.x, y = cur.y;
        Q.pop();
        if (y == N-1 && x == M-1) {
            res = dist[y][x][cur.f];
            break;
        }
        for(int i=0;i<4;++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if(!B(nx, ny) || dist[ny][nx][cur.f]) continue; // 이미 방문 했으면 패스
            if(map[ny][nx] == '1' && cur.f) continue; // 벽이고 이미 벽을 부쉈을 때
            if(map[ny][nx] == '1' && cur.f == 0) {
                Q.push({nx, ny, 1});
                dist[ny][nx][1] = dist[y][x][0] + 1;
            } else {
                Q.push({nx, ny, cur.f});
                dist[ny][nx][cur.f] = dist[y][x][cur.f] + 1;
            }
        }
    }
    cout << res;
}
