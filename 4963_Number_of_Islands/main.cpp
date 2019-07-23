#include <cstdio>
#include <cstring>
#include <queue>
int w,h, dx[] = {0,1,0,-1,1,1,-1,-1},dy[] = {1,0,-1,0,1,-1,1,-1};
struct P {int x,y;};
inline bool bound(P v) {return v.x>=0&&v.x<w&&v.y>=0&&v.y<h;}
short a[50][50]; // 1: land, 0: sea, 2: visited
const short V = 2;
void bfs(P s) {
    std::queue<P> Q;
    Q.push(s);
    a[s.y][s.x] = V;
    while(!Q.empty()) {
        P u = Q.front();
        Q.pop();
        for(int i=0;i<8;++i) {
            P v = {u.x+dx[i],u.y+dy[i]};
            if(bound(v) && a[v.y][v.x]==1) {
                Q.push({v.x,v.y});
                a[v.y][v.x] = V;
            }
        }
    }
}

int main() {
    int cnt;
    while(scanf("%d%d",&w,&h),(w||h)) {
        cnt = 0;
        for(int i=0;i<h;++i)
            for(int j=0;j<w;++j)
                scanf("%hd",&a[i][j]);
        for(int i=0;i<h;++i) {
            for(int j=0;j<w;++j) {
                if(a[i][j] == 1) {
                    cnt++;
                    bfs({j,i});
                }
            }
        }
        printf("%d\n",cnt);
    }
}