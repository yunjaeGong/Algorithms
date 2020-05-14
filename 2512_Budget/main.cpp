#include <iostream>
using namespace std;
int N, M;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    int *arr = new int[N];
    int sum = 0, left = 0, right = 0;
    for(int i=0;i<N;++i) {
        cin >> arr[i];
        sum += arr[i];
        right = max(right, arr[i]);
    }
    cin >> M;
    if(sum <= M) {
        cout << right;
        return 0;
    }
    int res = 0;
    while(left <= right) {
        int mid = (left + right)/2, budget = 0;
        for(int i=0;i<N;++i) { budget += min(mid, arr[i]); }
        if(budget > M) {
            right = mid-1;
        } else {
            left = mid+1;
            res = mid;
            if(budget == M) break;
        }
    }
    cout << res;
}
