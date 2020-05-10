#include <iostream>
using namespace std;
int N;
char board[2188][2188];
void paint(int r, int c, int size) {
    if(size == 1) {
        board[r][c] = '*';
        return;
    }
    for(int i=0, j;i<3;++i)
        for(j=0;j<3;++j) {
            if(i==1 and j==1) continue;
            paint(r+i*(size/3),c+j*(size/3),size/3);
        }
}
int main() {
    cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            board[i][j] = ' ';
    paint(0,0,N);
    for(int i=0;i<N;++i)
        cout << board[i] << '\n';
}
