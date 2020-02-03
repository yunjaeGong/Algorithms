#include <iostream>
char A[20][21];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, R, C;
bool visited[26];
int Max = 1;
int dfs(int x, int y, int cnt) {
    for(int i=0;i<4;++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if((nx >= 0 && nx < C && ny >= 0 && ny < R) && !visited[A[ny][nx]-'A']) {
            visited[A[ny][nx]-'A']= true;
            Max = std::max(Max, dfs(nx, ny, cnt+1));
            visited[A[ny][nx]-'A']= false;
        }
    }
    return cnt;
}

int main() {
    std::cin >> R >> C;
    for(int i=0;i<R;++i)
        std::cin >> A[i];
    visited[A[0][0]-'A'] = true;
    dfs(0,0,1);
    std::cout << Max;
}
