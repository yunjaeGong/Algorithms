#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define pss pair<short,short>
vector<int> v(101,0), res;
bool visited[101];
int N, in, Max=0;
void dfs(int start, int cur) { // n: 시작노드
    if(visited[cur]) { // 재방문 하는 경우
        if(start == cur) // 사이클이고,
            res.push_back(start);
    } else {
        visited[cur] = true;
        dfs(start, v[cur]);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;++i) {
        cin >> in;
        v[i] = in;
    }
    for(int i=1;i<=N;++i) {
        dfs(i, i);
        memset(visited,0,sizeof(visited));
    }
    cout << res.size() << '\n';
    for(int e:res)
        cout << e << '\n';
}
