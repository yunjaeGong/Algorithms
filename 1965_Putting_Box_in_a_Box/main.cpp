#include <cstdio>
#include <algorithm>
#include <vector>
int main() {
    short n;
    scanf("%hd",&n);
    short A[n];
    std::vector<short> v;
    for(int i=0;i<n;++i)
        scanf("%hd",&A[i]);
    v.push_back(A[0]);
    for(int i=1;i<n;++i) {
        if(A[i] > v.back()) {
            v.push_back(A[i]);
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), A[i]);
            if(it != v.end())
                *it = A[i];
        }
    }
    printf("%d",v.size());
}