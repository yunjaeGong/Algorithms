#include <iostream>
#include <cstring>

int N;
bool check(int p[], int i, int j) {
    for(int k=1;k<i;++k)
        if(p[k] == j) return false;
    return true;
}
void Permutation_1(int P[], int i, int k) { // bottom up
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
} // nPk
inline void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void Permutation_2(int P[],int i, int k) { // top down
    for(int j=i;j<=N;++j) { // j번째부터 시작
        swap(P[i],P[j]);
        if(i == k) { // i가 k이면 nPk 완성
            for(int l=1;l<=k;++l)
                printf("%c ",P[l]);
            printf("\n");
        } // 출력
        Permutation_2(P,i+1,k);
        swap(P[i],P[j]); // 원래 상태로 만들어야 이후 j+1번째부터 시작하는 순열 생성 가능
    }
}

int main() {
    int k;
    scanf("%d%d",&N,&k);
    int P[N+1];
    memset(P,0, sizeof(P));
    //Permutation_1(P,1,k); // bottom up
    for(int i=0;i<N;++i)
        P[i+1] = 'a'+i;
    Permutation_2(P,1,k); // top down
}