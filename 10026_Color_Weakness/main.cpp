#include <iostream>
#include <string.h>
#include <queue>
#define Pair pair<int,int>
#define mp make_pair
using namespace std;
int N;
int cnt;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void bfs(int i, int j, char a[][100], bool visited[][100]);
int main() {
    scanf("%d",&N);
    char arr[100][100];
    char b_arr[100][100];
    bool visited[100][100];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'G')
                b_arr[i][j] = 'R';
            else b_arr[i][j] = arr[i][j];
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!visited[i][j]) {
                bfs(i,j,arr,visited);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    cnt = 0;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(!visited[i][j]) {
                bfs(i,j,b_arr, visited);
                cnt++;
            }
        }
    }
    cout << cnt;
}
bool bound(Pair a) { return a.first >= 0 && a.first < N && a.second >= 0 && a.second < N; }
void bfs(int i, int j, char a[][100], bool visited[][100]) {
    queue<Pair> Q;
    Pair u = {i,j};
    Q.push(u);
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        char cur = a[u.first][u.second];
        for(int k=0; k<4; k++) {
            int nx = u.first+dx[k], ny = u.second+dy[k];
            if (!bound({nx,ny})) continue;
            if (visited[nx][ny]) continue;
            if (a[nx][ny] != cur) continue;
            Q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}