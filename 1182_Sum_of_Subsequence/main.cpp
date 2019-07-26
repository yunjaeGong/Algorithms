#include <cstdio>
int N,S,cnt=0;
int a[20];

void P(int x,int sum) {
    if (x >= N) {
        if (sum == S) cnt++;
        return;
    }
    P(x+1, sum+a[x]);
    P(x+1, sum);
}
int main() {
    scanf("%d%d",&N,&S);
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    P(0,0);
    if (S == 0) cnt--;
    printf("%d",cnt);
}