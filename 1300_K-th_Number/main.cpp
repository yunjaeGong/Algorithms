#include <iostream>
#define ll long long
using namespace std;
ll N, K, ans;
int main() {
    cin >> N >> K;
    ll l = 1, r = K, m;
    while(l <= r) { // K번째 수가 어떤 수인지 m보다 작은 수들의 개수를 이용해 범위를 줄여가며 찾음
        ll cnt = 0;
        m = (l+r)/2;
        for(int i=1;i<=N;i++)
            cnt += min(m/i, N); // m보다 작거나 같은 수의 개수들의 합
        if(cnt < K) // 합이 K보다 작으면? -> left = mid+1해서 다시 탐색
            l = m+1;
        else { // 합이 K보다 크거나 같으면? -> right = mid-1해서 다시 탐색
            r = m-1;
            ans = m;
        }
    }
    cout << ans;
}
