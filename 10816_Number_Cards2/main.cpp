#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);
    int N, M, find;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    cin >> M;
    for(int i=0,cnt=0;i<M;++i,cnt=0) {
        cin >> find;
        auto it_l = lower_bound(A.begin(), A.end(), find);
        auto it_r = upper_bound(A.begin(), A.end(), find);
        cout << (it_r - A.begin()) - (it_l - A.begin())<< " ";
    }
}
