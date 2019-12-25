#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct P{ int a, b, sum; };
bool comp(const P a, const P b) { return a.sum < b.sum; }

int main() {
    int Target, N, res = 0;
    std::cin >> N >> Target;
    int a[100];
    vector<P> v;

    for(int i=0;i<N;++i)
        cin >> a[i];

    for(int i=0;i<N;++i)
        for(int j=i+1;j<N;++j)
            v.push_back({i, j,a[i] + a[j]});

    sort(v.begin(), v.end(), comp);

    for (int i=0;i<N;++i) {
        P tmp = {i,i,Target - a[i]};
        auto it = lower_bound(v.begin(), v.end(), tmp, comp);
        if(it == v.end() || a[i] + it->sum > Target)
            --it;
        set<int> s = {it->a, it->b, i};
        if(s.size() == 3) {
            if(a[i] + it->sum == Target) {
                std::cout << Target; return 0;
            }
            if(a[i] + it->sum > res)
                res = a[i] + it->sum;
        }
    }
    std::cout << res;
}


/*
#include <iostream>
int main() {
    int i, j, k, N, M, arr[100], sum, res=0;
    std::cin >> N >> M;
    for(i=0; i<N; i++)
        std::cin >> arr[i]
    for(i=0;i<N-2;i++)
        for(j=i+1;j<N-1;j++)
            for(k=j+1;k<N;k++) {
                sum=arr[i]+arr[j]+arr[k];
                if(sum>ans&&sum<=M)
                    res=sum;}
    std::cout << res;
    return 0;
}*/
