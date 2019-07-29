#include <cstdio>
int N;
int main() {
    scanf("%d",&N);
    short a[N],lds[N],max=1;
    for(int i=0;i<N;++i)
        scanf("%hd",&a[i]);
    for(int i=0;i<N;++i)
        lds[i] = 1;
    for (int i=1;i<N;i++) {
        for (int j=0;j<i;j++) {
            if (a[i] < a[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
        }
        if(max < lds[i]) max = lds[i];
    }
    printf("%d",max);
}