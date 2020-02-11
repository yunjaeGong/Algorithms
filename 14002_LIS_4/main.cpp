#include <iostream>
#include <vector>
using namespace std;
int arr[1001], dp[1001];
int main() {
    int N, Max=1;
    cin >> N;
    vector<int> v;
    cin >> arr[0];
    dp[0] = 1;
    for(int i=1;i<N;++i) {
        cin >> arr[i];
        int tmp_max = 1;
        for(int j=0;j<i;++j) {
            if(arr[i] > arr[j])
                tmp_max = max(tmp_max, dp[j]+1);
            dp[i] = tmp_max;
            Max = max(tmp_max, Max);
        }
    }
    cout << Max << '\n';
    for(int i=N-1;i>=0&&Max>0;--i)
        if(Max == dp[i]) {
            v.push_back(arr[i]);
            Max--;
        }
    for(auto it=v.rbegin();it!=v.rend();++it)
        cout << *it << " ";
}