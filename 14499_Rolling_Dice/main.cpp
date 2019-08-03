#include <iostream>
#include <deque>
using namespace std;
int x,y,N,M,K,dx[]={1,-1,0,0},dy[]={0,0,-1,1};
deque<short> X_ax, Y_ax; // X, Y축
bool bound(int x, int y) {return x>=0&&x<M&&y>=0&&y<N;}
void roll(int op) {
    short y_f=Y_ax.front(), y_b=Y_ax.back();
    switch(op) {
        case 1: { // 동쪽
            X_ax.push_back(y_b); // 주사위 윗면을 오른쪽 면으로
            Y_ax.back() = X_ax.front(); // 주사위 왼쪽 면을 주사위 윗면으로
            X_ax.pop_front(); // 복사된 왼쪽면 삭제
            Y_ax[1] = X_ax[1]; // Y, X축 동기화
            break;
        }
        case 2: { // 서쪽
            X_ax.push_front(y_b);
            Y_ax.back() = X_ax.back();
            X_ax.pop_back();
            Y_ax[1] = X_ax[1];
            break;
        }
        case 3: { // 북쪽
            Y_ax.pop_back();
            Y_ax.push_front(y_b);
            X_ax[1] = Y_ax[1];
            break;
        }
        case 4: { // 남쪽
            Y_ax.pop_front();
            Y_ax.push_back(y_f);
            X_ax[1] = Y_ax[1];
            break;
        }
    }
}
int main() {
    scanf("%d%d%d%d%d",&N,&M,&y,&x,&K);
    short map[N][M], op;
    for(int i=0;i<N;++i) // 지도 입력
        for(int j=0;j<M;++j)
            scanf("%hd",&map[i][j]);
    for(int i=0;i<3;++i) {
        X_ax.push_back(0);
        Y_ax.push_back(0);
    }
    Y_ax.push_back(0);
    for(int i=0;i<K;++i) {
        scanf("%hd",&op);
        int n_x = x+dx[op-1],  n_y = y+dy[op-1];
        if(!bound(n_x,n_y)) continue;
        roll(op);
        if(map[n_y][n_x] == 0) {
            map[n_y][n_x] = X_ax[1]; // 현재 바닥 복사

        } else {
            X_ax[1] = map[n_y][n_x]; // 바닥을 주사위에 복사
            Y_ax[1] = X_ax[1];
            map[n_y][n_x] = 0;
        }
        printf("%d\n",Y_ax.back());
        x = n_x, y = n_y;
    }
}