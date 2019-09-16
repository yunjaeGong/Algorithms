#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
struct P{int a,b,sum;};
bool comp(const P a, const P b) { return a.sum<b.sum; }
int main() {
    int W, N;
    scanf("%d%d",&W,&N);
    int *a = new int[N];
    vector<P> v;
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<N;++i)
        for(int j=i;j<N;++j)
            v.push_back({i, j, a[i]+a[j]});
    sort(v.begin(), v.end(), comp);
    for (P p : v) {
        P tmp = {0,0,W-p.sum};
        auto it = lower_bound(v.begin(), v.end(), tmp, comp);
        while (it != v.end() && p.sum + it->sum == W) {
            set<int> s = {it->a, it->b, p.a, p.b};
            if(s.size() == 4) { printf("YES");return 0; }
            ++it;
        }
    }
    printf("NO");
}