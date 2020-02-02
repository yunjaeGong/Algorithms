#include <cstdio>
#include <cstring>
using namespace std;

bool map[100][100], res[100][100], visited[100];
int n;

void dfs(int j, bool res[]){
    for(int k=0;k<n;k++)
        if(map[j][k] && !visited[k]) {
            visited[k] = true;
            res[k] = true;
            dfs(k, res);
        }
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&map[i][j]);
    
    for(int i=0;i<n;i++) {
        memset(visited,0,sizeof(visited));
        dfs(i, res[i]);
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            printf("%d ", res[i][j]);
        printf("%c", '\n');
    }
}
