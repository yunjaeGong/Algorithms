#include <cstdio>
#include <queue>
#include <cstring>
// L: 왼, D: 오
char a[101][101];
int N, K, L,dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
std::pair<int,char> turn[100];
int last;
bool bound(int r, int c) {return r>0&&r<=N&&c>0&&c<=N;}
bool hit(int r, int c) {return a[r][c] > 0 && a[r][c] < 5;}
int sec=0;
void run() {
    int h_r=1, h_c=1,n_r = 1,n_c=2,dir=0,t_r=1,t_c=1;
    int i=0;
    a[1][1] = 1;
    while(!hit(n_r,n_c)&& bound(n_r,n_c)) {

        if(i<=last && turn[i].first == sec) {
            int d = turn[i].second=='D'?1:-1;
            dir = (dir+4+d)%4;
            i++;
        }
        a[h_r][h_c] = dir+1;
        n_r = h_r + dy[dir], n_c = h_c + dx[dir];

        if(a[n_r][n_c] != 'a') { // 사과면?
            int tmp_r=t_r, tmp_c = t_c;
            t_r += dy[a[tmp_r][tmp_c]-1], t_c += dx[a[tmp_r][tmp_c]-1];
            a[tmp_r][tmp_c] = 0;
        } // 사과 아니면 tail줄이기

        // head 이동
        h_r = n_r, h_c = n_c;
        //n_r = h_r + dy[dir], n_c = h_c + dx[dir]; // new head 이동
        //if(hit(n_r,n_c)|| !bound(n_r,n_c)) break;
        sec++;
        for(int i=1;i<=N;++i) {
            for(int j=1;j<=N;++j)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        printf("\n");
    }


}
int main() {
    //11시 58분
    int r,c,s;
    char d;
    scanf("%d %d",&N,&K);

    for(int i=0;i<N;++i)
        memset(a[i],0,N+1);
    for(int i=0;i<K;++i) {
        scanf("%d %d",&r,&c);
        a[r][c] = 'a';
    }
    scanf("%d",&L);
    for(int i=0;i<L;++i) {
        scanf("%d %c",&s,&d);
        turn[i] = {s,d};
        last = i;
    }
    run();
    printf("%d",sec);
}