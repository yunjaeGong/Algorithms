#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int vis[MAX];
int N, K;
int main() {
    queue<int> Q;
    cin >> N >> K;
    fill(vis, vis+MAX, INT32_MAX);
    vis[N] = 0;
    Q.push(N);
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if(cur == K)
            break;
        if(cur-1 >= 0 && vis[cur-1] > vis[cur]+1) {
            Q.push(cur-1);
            vis[cur-1] = vis[cur] + 1;
        }
        if(cur+1 <= K && vis[cur+1] > vis[cur]+1) {
            Q.push(cur+1);
            vis[cur+1] = vis[cur] + 1;
        }
        if(2*cur <= MAX) {
            Q.push(2*cur);
            vis[2*cur] = vis[cur];
        }
    }
    cout << vis[K];
}
