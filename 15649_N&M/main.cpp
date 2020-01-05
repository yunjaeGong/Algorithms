#include <iostream>
#include <cstring>
int N;
bool check(int p[], int i, int j) {
    for(int k=1;k<i;++k)
        if(p[k] == j) return false;
    return true;
}
void Permutation_1(int P[], int i, int k) {
    if(i<=k) {
        for(int j=1;j<=N;++j) {
            if(check(P,i,j)) P[i] = j;
            else continue;

            if(i == k) {
                for(int l=1;l<=k;++l)
                    printf("%d ",P[l]);
                printf("\n");
            }
            Permutation_1(P,i+1,k);
        }
    }
}
int main() {
    int k;
    scanf("%d%d",&N,&k);
    int P[N+1];
    memset(P,0, sizeof(P));
    Permutation_1(P,1,k);
}