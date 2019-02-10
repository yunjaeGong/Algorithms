#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
int dfs_cycle(int Adj_list[], int visited[], int u, const int start_vertex);
int main() {
    int times, n;
    cin >> times;
    vector<int> result;
    while(times) {
        int count = 0, v;
        cin >> n;
        int *visited = new int[n+1];
        int *Adj_list = new int[n+1];
        for(int i=1;i<=n;i++) {
            visited[i] = 0;
        }
        for(int i=1;i<=n;i++) {
            cin >> v;
            Adj_list[i] = v;
        }
        for(int i=1;i<=n;++i) {
            if (visited[i] == 0) {
                count += dfs_cycle(Adj_list, visited, i, i);
            }
        }
        result.push_back(count);
        delete[] visited, Adj_list;
        times--;
    }
    for(int i=0;i<result.size()-1;++i)
        cout << result[i] << endl;
    cout << result.back();
    return 0;
}

int dfs_cycle(int Adj_list[], int visited[], int u, const int start_vertex)
{ // 사이클이 존재하는지 확인하는 dfs
    int v = Adj_list[u];
    visited[u] = 1;
    if(v == start_vertex) {
        return 1;
    }
    else
        dfs_cycle(Adj_list,visited,v,start_vertex);
    return 1;
}