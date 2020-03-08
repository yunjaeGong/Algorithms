#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
short wall[50][51], rooms[50][51];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1}; // 서북동남
int n, m, rNum, area;
void dfs(int x, int y) {
    rooms[y][x] = rNum;
    area++;
    for(int i=0;i<4;++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if(rooms[ny][nx] == 0 || (wall[y][x] & (1<<i)))
            continue;
        dfs(nx, ny);
    }
}
int main() {
    cin >> n >> m; // m by n
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            cin >> wall[i][j];
    int rNum=0, maxArea=0;
    queue<pii> Q; queue<int> Q2;
    vector<int> areas;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j) {
            area = 0;
            dfs(i, j);
            areas.push_back(area);
            maxArea = max(area, maxArea);
            rNum++;
            Q.push({i, j});
        }

    set<int> S[rNum];
    bool visited[50][51];
    memset(visited, 0, sizeof(visited));
    while(!Q.empty()) {
        pii cur = Q.front();
        Q.pop();
        int x = cur.s, y = cur.f;
        visited[y][x] = true;
        for(int i=0;i<4;++i) {
            int nx = x + dx[i], ny = y + dy[i];
            // if((wall[y][x] & (1<<i))
            if(rooms[ny][nx] == rooms[y][x] || visited[ny][nx]) // visited 수정 필요할지도
                continue;
            S[rooms[y][x]].insert(rooms[ny][nx]);
        }
    }
    int bArea = 0;
    for(int i=1;i<rNum;++i) {
        for(int e:S[i])
            bArea = max(bArea, areas[i-1]+areas[e-1]);
    }
    printf("%d\n%d\n%d", rNum, maxArea, bArea);
}
