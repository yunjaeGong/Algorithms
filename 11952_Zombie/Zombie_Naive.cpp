// using Naive BFS to mark Dangerous Cities -> Runtime Error

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
Int d[100001];
void dijkstra(vector<int> map[], int s) {
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
        for(int to: map[from]) {
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
    cin >> N >> M >> K >> S;
    cin >> pcost >> qcost;
    vector<int> map[N+1];
    queue<pii> Q;
    for(int i=0;i<K;++i) {
        int Node;
        scanf("%d",&Node);
        //infile >> Node;
        zombie[Node] = true;
        Q.push({Node, 0});
    }
    for(int i=0;i<M;++i) {
        int u, v;
        scanf("%d%d",&u,&v);
        // infile >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    int max = 0;
    while(!Q.empty()) {
        pii Adj = Q.front();
        Q.pop();
        if(Adj.second == S) continue;
        for(int v:map[Adj.first]) {
            Q.push({v, Adj.second + 1});
            danger[v] = true;
        }
    }
    dijkstra(map, 1);
    printf("%lld",d[N]);
}