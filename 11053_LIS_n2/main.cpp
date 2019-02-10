#include <iostream>
using namespace std;
int main() {
    int n, max=0;
    cin >> n;
    int a[n+1], b[n+1]; // b: dp
    for(int i=1;i<=n;++i) {
        int tmp_max = 0; // 이전 LIS의 길이의 최대값을 저장할 변수
        scanf("%d",&a[i]);
        for(int j=1;j<i;++j) { // i-1 까지 돌면서
            if(a[i] > a[j]) // 증가하며
                if(b[j] > tmp_max) // 1 ~ i-1 구간 LIS 길이의 최대값을 구함.
                    tmp_max = b[j];
        }
        b[i] = tmp_max +1; // 구한 길이의 최대값 + 1 한게 i까지의 LIS 길이
        if(b[i]>max) max = b[i]; // 그 중 최대값을 찾음.
    }
    cout << max;
}