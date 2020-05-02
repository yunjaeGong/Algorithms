#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int R, C;
char map[25][26];
bool visited[25][26];
int cnt[25][26];
char road[] = {'|', '-', '1', '2', '3', '4', '+'}; // TODO: 방향전환!
int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
struct P {
    int r, c, dir;
} S, T, Mis;
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
    Q.push(S);
    while(!Q.empty()) {
        P cur = Q.front();
        Q.pop();
        visited[cur.r][cur.c] = true;
        bool pushed = false;
        for(int i=0;i<4;++i) {
            int nr = cur.r + dr[i], nc = cur.c + dc[i];
            if(!bound(nr, nc) || visited[nr][nc] || map[nr][nc] == '.' || map[nr][nc] == 'Z') continue;
            Q.push({nr,nc,i});
            pushed = true;
        }
        // 모든 방향 끊어진경우! -> cur: 끝점
        if(pushed) continue;
        int dir = new_dir(cur.dir, map[cur.r][cur.c]); // 현재 방문하는 파이프의 다음 방향
        Mis = {cur.r+dr[dir], cur.c+dc[dir]};
        return true;
    }
    return false;
}


/*bool flow(P cur, int dir) { // 통과되면 반환
    for(int i=0;i<4;++i) {
        int nr = cur.r + dr[i], nc = cur.c + dc[i];
        if(map[nr][nc] == 'Z') return true; // 도달 가능
        if(!bound(nr, nc) || visited[nr][nc] || map[nr][nc] == '.') continue;
        dir = new_dir(dir, map[nr][nc]); // 방문하는 파이프 따라 방향 결정
        if(flow({nr,nc}, dir))
            return true;
    }
    // 모든 방향 끊어진경우! -> cur: 끝점
    Mis = cur;
    *//*for(char r:road) {
        map[cur.r+dr[dir]][cur.c+dc[dir]] = r;

    }*//*
    // 진행방향
}*/
bool flow() { // 빈칸 찾는 함수
    queue<struct P> Q;
    int dir = 0;
    for(int i=0;i<4;++i) { // TODO: M 이후 다 띄어져 있을 때
        int r = S.r + dr[i], c = S.c + dc[i];
        if(!bound(r, c) || map[r][c] == '.') continue;
        if((dir = new_dir(i, map[r][c])) == -1) continue;
        Q.push({r,c,dir});
        cnt[r][c]++;
    }
    cnt[S.r][S.c]++;
    while(!Q.empty()) {
        P cur = Q.front();
        Q.pop();

        // for(int i=0;i<4;++i) { // 네 방향 대신 지정하는 방향으로만 이동하게!
        int nr = cur.r + dr[cur.dir], nc = cur.c + dc[cur.dir];
        // if(!bound(nr, nc) || map[nr][nc] == '.') continue;
        // TODO: 십자가일때 2회 방문 가능!
        if((cnt[nr][nc] == 1 && map[nr][nc] == '+') || (cnt[nr][nc]==0)) {
            if(map[nr][nc] == 'Z') {
                cnt[nr][nc] = cnt[cur.r][cur.c] + 1;
                return true;
            }
            // TODO: 방문 가능한지 방향 체크!
            if((dir = new_dir(cur.dir, map[nr][nc])) == -1) continue; // 다음 블럭의 방향
            Q.push({nr,nc,dir});
            cnt[nr][nc]++;
        }
        // pushed = true;
    }
    /*if(pushed) continue;
    int dir = new_dir(cur.dir, map[cur.r][cur.c]); // 현재 방문하는 파이프의 다음 방향
    Mis = {cur.r+dr[dir], cur.c+dc[dir]};
    return true;*/
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
    int i=0;
    for(;i<7;++i) {
        memset(cnt, 0, sizeof(cnt));
        map[Mis.r][Mis.c] = road[i];
        if(flow()) break;
    }
    cout << Mis.r+1 << " " << Mis.c+1 << " " <<road[i];
    //printf("%d %d %c",Mis.r+1,Mis.c+1,road[i]);
}
