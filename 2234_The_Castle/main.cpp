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
int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; // 서북동남
int n, m, rNum=1, area;
bool bound(int x, int y) {return x>=0&&x<n&&y>=0&&y<m;}
void dfs(int x, int y, queue<pii> &Q) {
    rooms[y][x] = rNum;
    area++;
    if(wall[y][x])
        Q.push({x,y});
    for(int i=0;i<4;++i) {
        if(wall[y][x] & (1<<i))
            continue;
        int nx = x + dx[i], ny = y + dy[i];
        if(!bound(nx, ny) || rooms[ny][nx] != 0)
            continue;
        dfs(nx, ny, Q);
    }
}
int main() {
    cin >> n >> m; // m by n
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            cin >> wall[i][j];
    int maxArea=0;
    queue<pii> Q;
    vector<int> areas;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j) {
            if(rooms[i][j])
                continue;
            area = 0;
            dfs(j, i, Q);
            areas.push_back(area);
            maxArea = max(area, maxArea);
            rNum++;
        }

    set<int> S[rNum];
    bool visited[50][51];
    memset(visited, 0, sizeof(visited));
    int bArea = 0;
    for(int y=0;y<m;++y) {
        for(int x=0;x<n;++x) {
            for(int i=0;i<4;++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(!bound(nx, ny) || rooms[ny][nx] == rooms[y][x]) // visited 수정 필요할지도
                    continue;
                if(wall[y][x] & (1<<i)) {
                    S[rooms[y][x]].insert(rooms[ny][nx]);
                    S[rooms[ny][nx]].insert(rooms[y][x]);
                }
            }
        }
    }

    for(int i=1;i<rNum;++i) {
        for(int e:S[i])
            if(e != i)
                bArea = max(bArea, areas[i-1]+areas[e-1]);
    }
    printf("%d\n%d\n%d", rNum-1, maxArea, bArea);
}
