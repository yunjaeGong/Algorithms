#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int R, C;
char map[25][26];
bool visited[25][26];
pair<int,int> dist[25][26];
char road[] = {'|', '-', '1', '2', '3', '4', '+'}; // TODO: 방향전환!
int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
struct P {
    int r, c, dir;
} S, T, Mis;
int pipes=1;
inline bool bound(int r, int c) { return r>=0&&r<R&&c>=0&&c<C; }
int new_dir(int d, char cur) {
    int r=-1;
    switch(cur) {
        case '|': if(d==0 || d==2) r=d; break;
        case '-': if(d==1 || d==3) r=d; break;
        case '+': r=d; break;
        case '1': if(d==0) r=1; else if(d==3) r=2; break;
        case '2': if(d==2) r=1; else if(d==3) r=0; break;
        case '3': if(d==1) r=0; else if(d==2) r=3; break;
        case '4': if(d==1) r=2; else if(d==0) r=3; break;
    }
    return r;
}
bool find() { // 빈칸 찾는 함수
    queue<struct P> Q;
    int dir;
    visited[S.r][S.c] = true;
    for(int i=0;i<4;++i) {
        int r = S.r + dr[i], c = S.c + dc[i];
        if(!bound(r, c) || map[r][c] == '.') continue;
        if((dir = new_dir(i, map[r][c])) == -1) continue;
        Q.push({r,c,dir});
    }
    while(!Q.empty()) {
        P cur = Q.front();
        Q.pop();
        visited[cur.r][cur.c] = true;
        int nr = cur.r + dr[cur.dir], nc = cur.c + dc[cur.dir];
        // if(!bound(nr, nc) || visited[nr][nc] || map[nr][nc] == '.' || map[nr][nc] == 'Z') continue;
        if(map[nr][nc] == '.') {
            Mis = {cur.r+dr[cur.dir], cur.c+dc[cur.dir], cur.dir};
            return true;
        };
        if((dir = new_dir(cur.dir, map[nr][nc])) == -1) continue;
        Q.push({nr,nc,dir});
        // 모든 방향 끊어진경우! -> cur: 끝점
    }
    return false;
}

bool flow() { // 올바른 블럭 찾는 함수
    queue<struct P> Q;
    int dir = 0, cnt=0;
    for(int i=0;i<4;++i) { // TODO: M 이후 다 띄어져 있을 때
        int r = S.r + dr[i], c = S.c + dc[i];
        if(!bound(r, c) || map[r][c] == '.') continue;
        if((dir = new_dir(i, map[r][c])) == -1) continue;
        Q.push({r,c,dir});
        dist[r][c].first++;
        cnt++;
    }
    dist[S.r][S.c].first++;
    while(!Q.empty()) {
        P cur = Q.front();
        Q.pop();
        cnt++;
        int nr = cur.r + dr[cur.dir], nc = cur.c + dc[cur.dir];
        // TODO: 십자가일때 여러번 방문 가능!
        if((map[nr][nc] == '+') || (dist[nr][nc].first==0)) {
            if(map[nr][nc] == 'Z') {
                dist[nr][nc].second = dist[cur.r][cur.c].second + 1;
                return true;
            }
            // TODO: 방문 가능한지 방향 체크!
            if((dir = new_dir(cur.dir, map[nr][nc])) == -1) continue; // 다음 블럭의 방향
            Q.push({nr,nc,dir});
            dist[nr][nc].first++;
            dist[nr][nc].second = dist[cur.r][cur.c].second + 1;
        }
    }
    return false;
}

int main() {
    cin >> R >> C;
    for(int i=0;i<R;++i) {
        cin >> map[i];
        for(int j=0;j<C;++j) {
            if(map[i][j] == 'M') {
                S = {i, j};
            } else if(map[i][j] == 'Z') {
                T = {i, j};
            }
        }
    }
    find();
    fflush(stdout);
    int i=0, min_dist = 0;
    char min_road;
    for(;i<7;++i) {
        memset(dist, 0, sizeof(dist));
        map[Mis.r][Mis.c] = road[i];
        if(!flow()) continue;

        if(min_dist < dist[T.r][T.c].second-1) {
            min_dist = dist[T.r][T.c].second-1;
            min_road = road[i];
        }
    }

    printf("%d %d %c",Mis.r+1,Mis.c+1,min_road);
} 
