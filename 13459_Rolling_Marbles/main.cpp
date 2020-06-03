#include <iostream>
#include <queue>
using namespace std;
int N, M;
char arr[10][11];
char visited[10][10];
int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
struct p { int r, c; }R,B,O;
inline bool bound(int r, int c) {return r>=0&&r<N&&c>=0&&c<M;}
void dfs(p red, p blue, int d, int cnt) {
    for(int i=0;i<4;++i) {
        int rr = red.r + dr[i],rc = red.c + dc[i];
        int br = blue.r + dr[i],bc = blue.c + dc[i];
        if(!bound(rr,rc)visited[][red.c])
    }


}
int main() {
    cin >> N >> M;
    for(int i=0;i<N;++i) {
        cin >> arr[i];
        for(int j=0;j<M;++j) {
            if(arr[i][j] == 'R')
                R = {i,j};
            else if(arr[i][j] == 'R')
                B = {i,j};
            else if(arr[i][j] == 'O')
                O = {i,j};
        }
    }
}
