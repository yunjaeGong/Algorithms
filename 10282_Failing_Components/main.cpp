#include <iostream>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
int N, M, C;
int dist[10001];
int main() {
    int T, u, v, w, cnt, time;
    cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);
    const int MAX = 1<<30;
    cin >> T;
    while(T--) {
        cnt = 0, time = 0;
        cin >> N >> M >> C;
        fill(dist, dist+N+1, MAX);
        vector<pii> V[N+1];
        priority_queue<pii, vector<pii>, greater<>> Q;
        Q.push({C, 0});
        for(int i=0;i<M;++i) {
            cin >> u >> v >> w;
            V[v].push_back({u,w});
        }
        dist[C] = 0;
        while(!Q.empty()) {
            pii cur = Q.top();
            Q.pop();
            for(pii adj: V[cur.f]) {
                if(dist[adj.f] <= dist[cur.f] + adj.s)
                    continue;
                dist[adj.f] = dist[cur.f] + adj.s;
                Q.push({adj.f, dist[adj.f]});
            }
        }
        for(int i=1;i<=N;++i) {
            if(dist[i] != MAX)
                cnt++;
            if(dist[i] != MAX && time < dist[i])
                time = dist[i];
        }
        cout << cnt << " " << time << '\n';
    }
}
