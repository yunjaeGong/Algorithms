#include <iostream>
char map[101][101];
int dx[] = {-1,-1,-1,0,0,1,1,1,}, dy[] = {-1,0,1,-1,1,-1,0,1};
using namespace std;
int main() {
    int R, C, nx, ny;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(std::cin >> R >> C,R && C) {
        for(int i=0;i<R;++i) {
            for(int j=0;j<C;++j)
                cin >> map[i][j];
        }
        for(int i=0;i<R;++i) {
            for(int j=0;j<C;j++) {
                int count = 0;
                for(int k=0;k<8;++k) {
                    ny = i+dy[k], nx = j+dx[k];
                    if(nx>-1 && nx<C && ny>-1 && ny<R)
                        count += (map[ny][nx] == '*'? 1 : 0);
                }
                cout << (char)(map[i][j]=='*'?'*':('0' + count));
            }
            cout << '\n';
        }
    }
}