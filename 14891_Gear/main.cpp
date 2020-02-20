#include <cstdio>
int ind[4] = {0,}; // 12시방향의 인덱스
char gear[4][9];
void rotate() { // r: 1 시계방향, -1 반시계방향
    int K,cnt=0;
    scanf("%d",&K);
    int n,r, left_p, right_p;
    for(int i=0;i<K;++i) {
        cnt=0;
        scanf("%d%d", &n, &r);
        n--;
        int lr = -r, rr = -r; // 왼쪽 오른쪽은 반대방향으로 회전
        for(int i=n;i>0;--i) { // N극은 0, S극은 1로 나타나있다.
            left_p = gear[i-1][(ind[i-1]+2)%8];
            if(left_p != gear[i][(ind[i]+6)%8])
                cnt++;// 극이 다르면
            else break;
        }
        for(int i=n,j=0;i>0&&j<cnt;++j,--i) { // 돌리기
            ind[i-1] = (ind[i-1]+8-lr)%8;
            lr *= -1;
        }
        cnt=0;
        for(int i=n;i<3;++i) {
            right_p = gear[i+1][(ind[i+1]+6)%8];
            if(right_p != gear[i][(ind[i]+2)%8])
                 cnt++; // 극이 다르면
            else break;
        }
        for(int i=n,j=0;i<3&&j<cnt;++j,++i) {
            ind[i+1] = (ind[i+1]+8-rr)%8;
            rr *= -1;
        }
        ind[n] = (ind[n]+8-r)%8; // n 회전
    }
}

int main() {
    for(int i=0;i<4;++i) {
        scanf("%s", gear[i]);
        for(int j=0;j<8;++j)
            gear[i][j]-='0';
    }
    rotate();
    int score = 0;
    for(int i=0, k=1;i<4;++i,k *= 2) // N극은 0, S극은 1로 나타나있다.
        if(gear[i][ind[i]]) score += k;
    printf("%d",score);
}