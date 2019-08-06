#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdint>
int N,M,dx[]={0,1,0,-1}, dy[] = {1,0,-1,0},min = INT32_MAX,max = 0,wall=0;
inline bool bound(int r,int c) {return r<N&&r>=0&&c<M&&c>=0;}
std::queue<std::pair<int,int>> ori_Q;
void mk_wall(short a[],int depth) {
    int cnt = 0;
    if(depth >= 3) {
        short cp[N*M];
        memcpy(cp,a,sizeof(cp));
        int r=0,c=0;
        // bfs 너비 탐색
        std::queue<std::pair<int,int>> Q(ori_Q);

        while(!Q.empty()) {
            r = Q.front().first, c = Q.front().second;
            Q.pop();
            for(int i=0;i<4;++i) {
                int n_r = r+dy[i], n_c = c+dx[i];
                if(!bound(n_r,n_c)||cp[(n_r)*M+n_c] != 0) continue;
                Q.push({n_r,n_c});
                cp[(n_r)*M+n_c] = 2;
            }
        }
        for(int i=0;i<N*M;++i)
            if(cp[i] == 0) cnt++;
    if(cnt > max) max = cnt;
    return;
    } // end of if
    else  {
        for(int i=0;i<N*M;++i) {
            if(a[i] != 0) continue;
            a[i] = 1; // 벽 세우기
            mk_wall(a,depth+1);
            // backtrack된 위치
            a[i] = 0;
        }
    }
}
int main() {
    scanf("%d%d",&N,&M);
    short a[N*M];
    for(int i=0;i<N*M;++i) {
        scanf("%hd",&a[i]);
        if(a[i] == 1)  wall++;
        if(a[i] == 2) ori_Q.push({i/M,i%M});
    }
    mk_wall(a,0);
    printf("%d",max);
}