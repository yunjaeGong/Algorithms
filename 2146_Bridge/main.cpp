#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N,C=2;
int visited[100][100];
int arr[100][100];
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

struct P {int x,y,s,L;}; // 각각 x, y좌표, set(섬 구분을 위한 정수), L(다리의 길이)

queue<P> Q; // 시작 위치를 저장할 큐
bool bound(P a) {return a.x>=0&&a.x<N&&a.y>=0&&a.y<N;}

int bfs(P a) { // Global Queue에 들어있는 각각의 원소(a) 위치부터 탐색
    int cnt = 0;
    queue<P> Q; // 방문할 정점(바다)을 저장할 큐
    Q.push({a.x, a.y, a.s, cnt});
    while(!Q.empty()) {
        P tmp = Q.front();
        Q.pop();
        arr[tmp.x][tmp.y] = -1; // 현재 방문중인 정점을 방문했다 표시
        for(int i=0;i<4;++i) { // 네 방향 탐색
            P nP = {tmp.x + dx[i],tmp.y + dy[i],tmp.s,tmp.L+1}; // 탐색할 위치 구조체. 현재 다리 길이(tmp.L)에서 1 증가시키고, 출발 섬 번호(tmp.s는 그대로 유지)
            if(bound(nP)&&arr[nP.x][nP.y]==0) { // 인접한 바다 방문 가능하면
                arr[nP.x][nP.y] = -1;
                Q.push({nP.x,nP.y,tmp.s,nP.L});
            }
            if(bound(nP)&&arr[nP.x][nP.y]>0 && arr[nP.x][nP.y]!= tmp.s) { // 다른 섬을 만나면 다리 길이를 반환하고 종료
                return nP.L;
            }
        }
    }
    return INT32_MAX;
}

void dfs(int x, int y) { // DFS를 이용해 섬 의 가장자리(바다와 인접한 정점들 & 탐색의 시작점) 추가
    visited[x][y] = C; // 섬 구분을 위한 전역변수 C (1,2,3..)
    for(int i=0;i<4;++i) {
        P nP = {x+dx[i], y+dy[i]}; // 방문할 정점
        if(bound(nP)&&visited[nP.x][nP.y]==0) Q.push({nP.x,nP.y,visited[x][y]}); // 가장자리 큐에 추가
        if(bound(nP)&&visited[nP.x][nP.y]==1) {
            dfs(nP.x,nP.y);
        }
    }
}
int main() {
    scanf("%d",&N);

    for(int i=0;i<N;++i)
        for (int j=0;j<N;++j)
            scanf("%d",&visited[i][j]);

    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            if(visited[i][j] == 1) { // 추가 끝나면 다음 섬으로 이동
                dfs(i,j);
                C++; // 방문하는 섬마다 다른 숫자로(>1) 방문했다 표시
            }
        }
    }
    int min = INT32_MAX;
    while(!Q.empty()) { // 탐색을 시작할 섬의 가장자리 정점들을 가지는 Global Queue
        memcpy(arr,visited,sizeof(arr)); // 서로 다른 수로 구분된 섬을 가지는 배열을 복사해 BFS 탐색에서 사용
        int tmp = bfs(Q.front()); // 다리의 최단 거리/INF를 반환(도달 불가)
        if(min > tmp) min = tmp;
        Q.pop();
    }
    cout << min;
}
