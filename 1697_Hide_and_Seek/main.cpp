#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N,K;
int d[] = {1,-1};
int main() {
    int visited[100002];
    memset(visited,0,sizeof(visited));
    scanf("%d%d",&N,&K);
    queue<int> Q;
    Q.push(N);
    while(!Q.empty()) {
        int tmp=Q.front();
        Q.pop();
        if(tmp == K) {
            cout << visited[tmp];
            return 0;
        }
        for(int i=0;i<3;++i) {
            int nP;
            if(i==2) nP = 2*tmp;
            else nP = tmp + d[i];
            if((nP>=0&&nP<=100000)&&(visited[nP]==0||visited[nP]>visited[tmp]+1)) {
                Q.push(nP);
                visited[nP] = visited[tmp]+1;
            }
        }

    }
}