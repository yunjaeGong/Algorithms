#include <iostream>
#include <vector>
using namespace std;
const int MAX = 50001;
int DP[MAX];
int main() {
    int n;
    cin >> n;
    vector<int> sq;
    for(int i=1;i<230;++i) // 제곱수들 벡터에
        sq.push_back(i*i);
    DP[0] = 0, DP[1] = 1;
    for(int i=2;i<=n;++i) {
        int min_num = 1<<30;
        for(int j=0;sq[j]<=i;++j) // DP[i]는 i를 만드는데 필요한 제곱수의 개수
             min_num= min(min_num, DP[i-sq[j]]); // i를 만드는데 필요한 제곱수들의 개수는 i에서 제곱수를 뺀 수들의 제곱수 +1, 그 중 최솟값
        DP[i] = min_num+1;
    }
    cout << DP[n];
}
