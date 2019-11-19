#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;
bool comp_a(const pii &a, const pii &b) {
    return a.first > b.first;
}
bool comp_b(const pii &a, const pii &b) {
    return a.second > b.second;
}

int main() {
    int N, Case = 1;

    while(cin >> N) {
        int ind = 0;
        vector<pii> v_a, v_b;
        int *arr = new int[N], *brr = new int[N];
        for(int i=0;i<N;++i)
            scanf("%d",&arr[i]);
        for(int i=0;i<N;++i)
            scanf("%d", &brr[i]);
        for(int i=0;i<N;++i) {
            v_a.emplace_back(make_pair(arr[i],i+1));
            v_b.emplace_back(make_pair(brr[i],i+1));
        }
        sort(v_a.begin(), v_a.end(), greater<>());
        sort(v_b.begin(), v_b.end(), greater<>());
        for(;ind<N;++ind) {
            if(v_a[ind].second != v_b[ind].second) {
                printf("Case %d: %d\n", Case, ind+1);
                break;
            }
        }
        if(ind == N) {
            printf("Case %d: agree\n", Case);
        }
        Case++;
    }
}
