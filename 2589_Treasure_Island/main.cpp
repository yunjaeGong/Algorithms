#include <iostream>
#include <queue>
#include <cstring>

#define pii pair<int, int>
char map[50][51];
bool visited[50][51];
int dx[] = {1,0,-1,0}, dy[] = {0, 1, 0, -1}, N, M, dist[50][50];
int MAX = 0;
using namespace std;
void find_treasure(int x, int y) {
    queue<pii> Q;
    Q.push({x, y});
    visited[y][x] = true;
    while(!Q.empty()) {
        pii cur = Q.front();
        int cur_x = cur.first, cur_y = cur.second;
        Q.pop();
        for (int i=0;i<4;++i) {
            int nx = dx[i] + cur_x, ny = dy[i] + cur_y;
            if(nx >= 0 && ny >= 0 && nx < M && ny < N) { // 범위 내
                if (map[cur_y][cur_x] == 'L' && !visited[cur_y][cur_x]) {
                     if(dist[ny][nx] > dist[cur_y][cur_x] + 1) {
                         dist[ny][nx] = dist[cur_y][cur_x] + 1;
                         Q.push({nx, ny});
                         visited[ny][nx] = true;
                     }
                }
            }
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(dist[i][j])
                MAX = std::max(MAX, dist[i][j]);
}

int main() {
    cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);
    cin >> N >> M;
    queue<pii> search_Q;

    for(int i=0;i<N;i++) {
        cin>>map[i];
        for(int j=0;j<M;j++)
            if(map[i][j]=='L')
                search_Q.push({i,j});
    }

    while(!search_Q.empty()) {
        memset(dist, 0, sizeof(dist));
        memset(visited, 0, sizeof(visited));
        pii cur = search_Q.front();
        search_Q.pop();
        find_treasure(cur.first, cur.second);
    }

    cout << MAX;
}
