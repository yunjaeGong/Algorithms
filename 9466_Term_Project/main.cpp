#include <iostream>
#include <cstring>
#define bound(i) (i>0&&i<=N)
using namespace std;
int inp[100001];
bool fin[100001], visited[100001];
int N,K,cnt=0;
void dfs(int cur) {
    int u = inp[cur];
    visited[cur]= true;
    if(bound(u)&&!visited[u]) {
        dfs(u);
    } else if(!fin[u]) {
        for(int v=u;v!=cur;v=inp[v]) {
            // fin[v] = true;
            cnt++;
        }
        cnt++;
    }
    fin[cur] = true;
}

int main() {
    scanf("%d",&K);
    while(K) {
        cnt = 0;
        memset(visited,false,sizeof(visited));
        memset(fin,false,sizeof(fin));
        scanf("%d",&N);
        for(int i=1;i<=N;++i)
            scanf("%d",&inp[i]);

        for(int i=1;i<=N;++i) {
            if(!visited[i])
                dfs(i);
        }
        K--;
        cout << N-cnt << endl;
    }


}