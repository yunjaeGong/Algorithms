#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
int beers;
bool visited[102];

inline int reachable(pii a, pii b) {
    return ((a.f-b.f)<0?b.f-a.f:a.f-b.f)
    + ((a.s-b.s)<0?b.s-a.s:a.s-b.s);
}

bool dfs(vector<pii> V, int cur) {
    int dist;
    for(int i=0;i<V.size();++i) {
        dist = (int)ceil((reachable(V[cur], V[i])/50.0));
        if(visited[i] || dist>20)
            continue;
        beers-=dist;
        if(beers < 0)
            return false;
        if(i == V.size()-1)
            return true;
        beers=20;
        visited[i] = true;
        if(dfs(V, i))
            return true;
        visited[i] = false;
    }
}

int main() {
    int T, n, x, y;
    cin >> T;
    while(T--) {
        vector<pii> V;
        beers = 20;
        cin >> n;
        for(int i=0;i<n+2;++i) {
            cin >> x >> y;
            V.emplace_back(x, y);
        }
        memset(visited,0,102);
        visited[0] = true;
        if(dfs(V, 0))
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}
