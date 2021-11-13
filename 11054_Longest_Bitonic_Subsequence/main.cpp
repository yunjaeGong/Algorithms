#include <iostream>
using namespace std;
int lis[1002], lds[1002], seq[1002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;
    for(int i=1;i<=n;++i)
        cin >> seq[i];

    // LIS
    for(int i=1;i<=n;++i) {
        int tmp_max=0;
        for(int j=1;j<i;++j) {
            if(seq[j] < seq[i]) {
                tmp_max = max(tmp_max, lis[j]); // 자기 자신만 사용하는 경우, 이전 LIS에 덧붙이는 경우
            }
        }
        lis[i] = tmp_max+1;
    } // 0~k 까지의 LIS => LIS[k]

    // LDS
    for(int i=n;i>0;--i) {
        int tmp_max=0;

        for(int j=n,tmp=1;i<j;--j) {
            if(seq[i] > seq[j]) {
                tmp_max = max(tmp_max, lds[j]); // 자기 자신만 사용하는 경우, 이전 LIS에 덧붙이는 경우
            }
        }
        lds[i] = tmp_max+1;
    } // k~n 까지의 LDS => LDS[k]
    lds[0] = 1;
    lis[n+1] = 1;
    // Bitonic
    int MAX = 1;
    for(int i=0;i<=n+1;++i) {
        MAX = max(MAX, lis[i] + lds[i] - 1);
    }

    cout << MAX;
}
