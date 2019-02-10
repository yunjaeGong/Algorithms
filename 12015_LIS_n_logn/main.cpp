#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    int* A = new int[n];
    vector<int> v;
    for(int i=0;i<n;++i)
        scanf("%d",&A[i]);
    /*int max = 0, prev = 0;
    for(int i=0;i<n;++i) {
        vector<int>::iterator it = v.begin();
        int tmp = 0;
        do {
            it = upper_bound(it,v.end(),*it);
            tmp++;
        }while(bool(it != v.end()));

        if(tmp > max) max = tmp;
    }*/
    // 주어진 수열에서 v[0] ~ v[n-1] 시작하는 LIS를 각각 찾고, 그중 최대값을 찾는 알고리즘 n^2 log n
    v.push_back(A[0]);
    for(int i=1;i<n;++i) {
        if(A[i] > v.back()) {
            v.push_back(A[i]);
        }
        else {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), A[i]);
            if(it != v.end())
                *it = A[i];
        }
    }
    cout << v.size();
}