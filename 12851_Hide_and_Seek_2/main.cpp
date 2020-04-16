#include <iostream>
#include <queue>
#define MAX 100001
struct route{int d,p;}; // 거리, 경우의 수
using namespace std;
int N,K;
int d[] = {1,-1};
bool visited[3][MAX];
route map[MAX];
int main() {
    cin >> N >> K;
    map[N].p = 1;
    queue<int> Q;
    if(N == K) {
        cout << map[K].d << '\n' << map[K].p;
        return 0;
    }
    Q.push(N);
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int i=0;i<3;++i) {
            int nP;
            if(i==2) nP = 2*cur;
            else nP = cur + d[i];
            if((nP>=0&&nP<MAX) && (map[nP].d==0 || map[nP].d >= map[cur].d + 1)) { // 범위 내이고, 방문 안했거나, 최단거리/재방문하는 경우이면
                Q.push(nP);
                if(map[nP].d == map[cur].d + 1 && !visited[i][nP]) { // 재방문 (경우의 수 증가)
                    map[nP].p += map[cur].p;
                } else if(map[nP].d==0 || map[nP].d > map[cur].d + 1) { // 최단경로
                    map[nP].d = map[cur].d + 1;
                    map[nP].p = map[cur].p;
                    for(int k=0;k<3;visited[k++][nP]=false);
                }
                visited[i][nP] = true;
            }

        }
    }
    cout << map[K].d << '\n' << map[K].p;
}