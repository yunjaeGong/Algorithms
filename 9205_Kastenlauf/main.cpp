#include <iostream>
#include <queue>
#include <cstring>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
bool visited[102];
struct Pos{
    int x, y, idx;
};
inline bool reachable(Pos a, pii b) {
    return (abs(a.x-b.f) + abs(a.y-b.s))<=1000;
}

int main() {
    int T, n, x, y;
    bool res;
    cin >> T;
    while(T--) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        cin >> n;
        queue<Pos> Q;
        vector<pii> V;
        res = false;
        for(int i=0;i<n+2;++i) {
            cin >> x >> y;
            V.push_back({x, y});
        }
        memset(visited,0,sizeof(visited));
        Q.push({V[0].f, V[0].s, 0});
        while(!Q.empty()) {
            Pos cur = Q.front();
            Q.pop();
            visited[cur.idx] = true;
            for(int i=0;i<n+2;++i) {
                if(visited[i] || !reachable(cur, V[i]))
                    continue;
                if(i == n+1) {
                    res = true;
                    break;
                }
                Q.push({V[i].f, V[i].s, i});
            }
            if(res)
                break;
        }
        if(res)
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}
