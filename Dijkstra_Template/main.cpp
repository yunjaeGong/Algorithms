#include <iostream>
#include <vector>
#include <queue>
#define N 1000
#define w first
#define adj second

using namespace std;

typedef pair<int, int> pii;

int dist[N+1];

class comp {
public:
    bool operator()(pii &lhs, pii& rhs) {
        return lhs.first < rhs.first;
    };
};

void dijkstra(const int s, vector<pii> map[]) {
    priority_queue<pii, vector<pii>, comp> pq; // first, second 순으로 sort. 순서가 마음에 안들면 comparator
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        for(pii v:map[cur.adj]) {
            if(dist[v.adj] <= v.w + dist[cur.adj])
                continue;
            dist[v.adj] = v.w + dist[cur.adj];
            pq.push(v);
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, e, u, v, w, s;
    cin >> n >> e;
    cin >> s;

    vector<pii> map[n+1];
    fill(dist, dist+n+1, 1<<30);

    for(int i=0;i<e;++i) {
        cin >> u >> v >> w;
        map[u].push_back({w, v});
    }

    dijkstra(s, map);

    for(int i=1;i<=n;++i)
        cout << dist[i] << " ";
}
