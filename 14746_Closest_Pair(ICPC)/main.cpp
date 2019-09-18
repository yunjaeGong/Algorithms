#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int P,Q, p_y, q_y;
    cin >> P >> Q >> p_y >> q_y;
    vector<int> Ps(P), Qs(Q);
    for(int i=0;i<P;++i)
        cin >> Ps[i];
    for(int i=0;i<Q;++i)
        cin >> Qs[i];
    int cnt=1;
    int min = INT32_MAX;
    sort(Ps.begin(),Ps.end());
    for(int i=0;i<Q;++i) {
        auto it = lower_bound(Ps.begin(),Ps.end(),Qs[i]);
        if(it != Ps.end() && min > abs(*it - Qs[i])) {
            min = abs(*it - Qs[i]);
            cnt = 1;
        }else if(it != Ps.end() && min == abs(*it - Qs[i]))
            cnt += 1;
        if(it != Ps.begin()) {
            it--;
            if(min > abs(*it - Qs[i])) {
                min = abs(*it - Qs[i]);
                cnt=1;
            }
            else if(min == abs(*it - Qs[i]))
                cnt += 1;
        }
    }
    cout << min + abs(q_y - p_y) << " " << cnt;
}