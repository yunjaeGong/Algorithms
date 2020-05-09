#include <iostream>
#include <vector>
using namespace std;
int N, arr[20][20];
int MIN = 1<<30;
bool visited[20];
vector<int> vis_s;
void dfs(int cur, int dep) {
    if(dep == N/2) {
        int sum_start, sum_link;
        vector<int> vis_l;

        for(int i=0;i<N;++i) {
            if(visited[i]) continue;
            vis_l.push_back(i);
        }
        int len = vis_l.size();
        for(int i=0;i<len;++i) {
            sum_start = arr[vis_s[i]][vis_s[(i+1)%len]];
            sum_link = arr[vis_l[i]][vis_l[(i+1)%len]];
        }
        MIN = min(MIN, abs(sum_start-sum_link));
        return;
    }
    for(int i=cur+1;i<N;++i) {
        if(visited[i]) continue;
        visited[i] = true;
        vis_s.push_back(i);
        dfs(i, dep+1);
        visited[i] = false;
    }
}
int main() {
    cin >> N;

    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cin >> arr[i][j];
    dfs(0,0);
    cout << MIN;
}
