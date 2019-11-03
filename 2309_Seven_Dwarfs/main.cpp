#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[10];
bool vis[10];

vector<int> v;
vector<int> ans;

void dfs(int ind, int cnt, int sum){
    // 정답을 찾은 경우
    if(cnt==7 && sum==100){
        ans.clear();
        for(int i=0; i<v.size(); i++){
            ans.push_back(arr[v[i]]);
        }
        sort(ans.begin(), ans.end());
        return;
    }

    for(int i=ind; i<=9; i++){
        if(!vis[i]){
            v.push_back(i);
            vis[i] = true;
            dfs(i,cnt+1, sum + arr[i]);
            vis[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    for(int i=1; i<=9; i++)
        scanf("%d",&arr[i]);

    memset(vis, false, sizeof(vis));

    dfs(1,0,0);
    for(int e:ans) {
        printf("%d\n",e);
    }
}