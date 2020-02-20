#include <cstdio>
#include <queue>
// L: 왼, D: 오
char a[101][101];
int N, K, L, dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
std::pair<int,char> turn[100];
int last;

void print() {
    for(int i=1;i<=N;++i) {
        for(int j=1;j<=N;++j)
            printf("%2d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
    fflush(stdout);
}

bool bound(int r, int c) {return r>0&&r<=N&&c>0&&c<=N;}
bool hit(int r, int c) {return a[r][c] > 0 && a[r][c] < 5;}
int sec = 0;
void run() {
    int h_r=1, h_c=1,n_r = 1,n_c=2,dir=0,t_r=1,t_c=1; // 현재 머리, 새 머리
    int i = 0;
    a[1][1] = 1;
    while(1) {

        if(i<=last && turn[i].first == sec) { // 돌아야하면
            int d = turn[i].second=='D'?1:-1;
            dir = (dir+4+d)%4;
            i++;
            a[h_r][h_c] = dir+1; // 회전 저장
        }
        // head 이동
        n_r = h_r + dy[dir], n_c = h_c + dx[dir];; // new head 이동
        if(hit(n_r, n_c) || !bound(n_r,n_c)) break;

        if(a[n_r][n_c] != 'a') { // 정상진행
            int tmp_r=t_r, tmp_c = t_c;
            t_r += dy[a[tmp_r][tmp_c]-1], t_c += dx[a[tmp_r][tmp_c]-1];
            a[tmp_r][tmp_c] = 0; // head == tail이면?
        } // 사과 아니면 tail줄이기

        a[n_r][n_c] = dir+1; // 이동방향 기억
        h_r = n_r, h_c = n_c; // 새 위치로 이동
        sec++;
        print();
    }

}
int main() {
    int r,c,s;
    char d;
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;++i)
        std::fill(a[i], a[i]+N, 0);
    for(int i=0;i<K;++i) {
        scanf("%d %d", &r, &c);
        a[r][c] = 'a';
    }
    scanf("%d", &L);
    for(int i=0;i<L;++i) {
        scanf("%d %c", &s, &d);
        turn[i] = {s, d};
        last = i;
    }
    run();
    printf("%d", sec+1);
}