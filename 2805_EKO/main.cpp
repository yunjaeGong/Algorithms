#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int N, M;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll in, left = 0, right = 0;
    cin >> N >> M;
    int *arr = new int[N];
    for(int i=0;i<N;++i) {
        cin >> arr[i];
        right = max((int)right, arr[i]);
    }
    int res = 0;
    while(left <= right) {
        ll len = 0;
        int mid = (left+right)/2;
        for(int i=0;i<N;++i) { len += (arr[i]-mid)>=0?arr[i]-mid:0; }
        if(len < M)
            right = mid-1;
        else {
            left = mid+1;
            res = mid;
            if(len == M) break;
        }
    }
    cout << res;
}
