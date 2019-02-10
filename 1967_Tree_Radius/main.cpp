#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    vector<vector<pair<int,int>>> Adj(n+1);
    vector<vector<int>> L(n+1);
    for(int i=0,u,v,w;i<n-1;++i) {
        scanf("%d %d %d",&u,&v,&w);
        Adj[u].push_back({v,w});
    }
    int Max = 0;
    for(int i=n;i>0;--i) {
        if(Adj[i].empty()) {
            L[i].push_back(0), L[i].push_back(0);
            continue;
        }
        for(vector<pair<int,int>>::iterator it = Adj[i].begin();it!=Adj[i].end();it++)
            L[i].push_back(it->second + max(L[it->first].front(),L[it->first].back()));
        for(;L[i].size()<2;)
            L[i].push_back(0);
        if(L[i].front() + L[i].back() > Max)
            Max = L[i].front() + L[i].back();
    }
    cout << Max;
    return 0;
}