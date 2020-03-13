#include <iostream>
#include <algorithm>
int N, M;
using namespace std;
int P[9];
int used[10001];
void swap(int &a, int &b) {int t=a;a=b;b=t;}
void permu(int i) { // top down
    for(int j=i;j<=N;++j) { // j번째부터 시작
        swap(P[i],P[j]);
        if(used[P[i]])
            continue;
        if(i == M) { // i가 k이면 nPk 완성
            for(int l=1;l<=M;++l)
                printf("%d ",P[l]);
            printf("\n");
        } // 출력
        used[P[i]] = true;
        permu(i+1);
        used[P[i]] = false;
        swap(P[i],P[j]); // 원래 상태로 만들어야 이후 j+1번째부터 시작하는 순열 생성 가능
    }
}
int main() {
    cin >> N >> M;
    for(int i=1;i<=N;++i)
        cin >> P[i];
    sort(P+1,P+N+1);
    permu(1);
}
