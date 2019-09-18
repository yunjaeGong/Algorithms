#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    int N, K, cur;
    cin >> N >> K;
    int Q[K];
    memset(Q,0,sizeof(int)*K);
    while(N--) {
        cin >> cur;
        int max_ind = -1;
        for(int i=0;i<K;++i) {
            if(Q[i] < cur) {
                if(max_ind == -1 || Q[max_ind] < Q[i])// 작고, 가장 큰 인덱스 찾기
                    max_ind = i;
            }
        }
        if(max_ind == -1) {
            printf("NO");
            return 0;
        }
        Q[max_ind] = cur;
    }
    printf("YES");
    return 0;
}