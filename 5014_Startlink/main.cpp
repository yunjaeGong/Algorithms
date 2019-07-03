#include <iostream>
#include <queue>
int F,S,G,U,D;
using namespace std;
queue<int> Q;
bool bound(int i) {return i>0&&i<=F;}
int bfs(int *visited) {
    visited[S] = 0;
    while(!Q.empty()) {
        int tmp = Q.front();
        Q.pop();
        if(tmp == G) return visited[tmp];
        if(bound(tmp+U)&&visited[tmp+U] > visited[tmp]+1) {
            visited[tmp+U] = visited[tmp]+1;
            Q.push(tmp+U);
        } if(bound(tmp-D)&&visited[tmp-D] > visited[tmp]+1) {
            visited[tmp-D] = visited[tmp]+1;
            Q.push(tmp-D);
        }
    }
    return -1;
}
int main() {
    cin>>F>>S>>G>>U>>D;
    int ans;
    int *a = new int[1000001];
    for(int i=1;i<=F;++i)
        a[i] = INT32_MAX;
    Q.push(S);
    if((ans = bfs(a)) != -1)
        cout << ans;
    else cout << "use the stairs";
    delete[] a;
}