#include <iostream>
#include <vector>
#include <queue>
#define INF (1LL << 60)
using namespace std;

typedef long long Int;
typedef pair<Int,Int> pii;

int N,M,K,S,pcost,qcost;
bool zombie[100001];
bool danger[100001];

void dijkstra(vector<int> map[], Int d[], int s) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    fill(d, d + 100001, INF);

    d[s] = 0;
    pq.push(pii(0, s));

    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        Int from = u.second;
        Int dist = u.first;
        if(d[from] < dist)continue;
        // 인접한 도시들 거리 업데이트
        for(auto to: map[from]) {
            int cost = pcost;
            if(zombie[to])
                continue;
            if(danger[to])
                cost = qcost;
            if(to == N)
                cost = 0;
            if(d[to] > d[from] + cost) {
                d[to] = d[from] + cost;
                pq.push({d[to], to});
            }
        }
    }
}

int main() {
    // 도시의 수, 길의 수, 좀비에게 점령당한 도시의 수, 위험한 도시의 범위
    cin >> N >> M >> K >> S;
    cin >> pcost >> qcost;
    vector<int> map[N+1];
    queue<int> Q;
    Int *d = new Int[100001];
    for(int i=0;i<K;++i) {
        int Node;
        scanf("%d",&Node);
        zombie[Node] = true;
        Q.push(Node);
    }
    for(int i=0;i<M;++i) {
        int u, v;
        scanf("%d%d",&u,&v);
        map[u].push_back(v);
        map[v].push_back(u);
    }
    // mark dangerous cities
    for(int i=0;i<=S;++i) {
        if(Q.empty()) break;
        int size = Q.size();
        for(int j=0;j<size;++j) {
            int Adj= Q.front();
            Q.pop();
            if(danger[Adj])continue;
            danger[Adj] = true;
            for(int v:map[Adj]) {
                Q.push(v);
            }
        }
    }
    // 다익스트라 호출
    dijkstra(map, d, 1);
    printf("%lld",d[N]);
    delete[] d;
}