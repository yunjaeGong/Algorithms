#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M, tmp;
    scanf("%d", &N);
    vector<int> a(N);
    for (int i=0;i<N;++i) {
        scanf("%d",&tmp);
        a[i] = tmp;
    }
    sort(a.begin(), a.end());
    scanf("%d",&M);
    for(int i=0;i<M;++i) {
        scanf("%d", &tmp);
        int l = 0, r = N-1;
        while(l <= r) {
            int mid = (l + r)/2;
            if(a[mid] == tmp) {
                printf("1 ");
                break;
            } else if(a[mid] > tmp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            if(l > r)
                printf("0 ");
        }
    }
}