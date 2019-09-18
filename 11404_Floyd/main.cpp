#include <iostream>
#include <cstring>

int N, E;
struct P{int x, y;};
inline int min(int a, int b) {return a>b?b:a;}
int main() {
    int u,v,w;
    scanf("%d%d",&N,&E);
    int *map[N];
    for(int i=0;i<N;++i) {
        map[i] = new int[N];
        memset(map[i],0,sizeof(int)*N);
    }
    for(int i=0;i<E;++i) {
        scanf("%d%d%d",&u,&v,&w);
        if(!map[u-1][v-1] || map[u-1][v-1] > w)
            map[u-1][v-1] = w;
    }
    for(int k=0;k<N;++k) {
        for(int i=0;i<N;++i) {
            for(int j=0;j<N;++j) {
                if (i == j)
                    continue;
                if (map[i][k] == 0 || map[k][j] == 0)
                    continue;
                if (map[i][j] == 0)
                    map[i][j] = map[i][k] + map[k][j];
                else
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}