#include <cstdio>
#include <cstring>
int dx[] = {0,1,0,-1},dy[] = {-1,0,1,0},C,R,K;
inline bool bound(int x, int y) {return x>=0&&x<C&&y>=0&&y<R;}
int main() {
    int d=0,i=0; // 가로 세로
    scanf("%d%d%d",&C,&R,&K);
    int x = 0,y = R-1, cnt=0;
    int **a = new int*[R];
    for(int k=0;k<R;++k) {
        a[k] = new int[C];
        memset(a[k],0,sizeof(int)*C);
    }
    int t_x = x,t_y = y;
    while(1) {
        if(bound(t_x,t_y) && a[t_y][t_x] == 0) { // 배열 범위 내이고, 아직 할당 안했으면
            cnt=0; // 카운트(종료 확인용) 초기화
            a[t_y][t_x] = ++i; // 채우기
            if(i == K) { // 찾는 위치이면 반환
                printf("%d %d\n",t_x+1,R-(t_y));
                break;
            }
            x = t_x, y = t_y; // 탐색한 위치 기본 위치로
        }
        else { // 방향을 바꿔야 할 때
            (++d)%=4; // 시계 방향으로 방향 바꿈
            cnt++; // 방향 바꾼 카운트 증가
            if(cnt >=4) { // 방향을 4번 연달아 바꾸면 -> 더 이상 방문할 위치가 없으면
                printf("%d",0); // 반환
                break;
            }
        }
        t_x = x + dx[d],t_y = y+dy[d];
    }
}