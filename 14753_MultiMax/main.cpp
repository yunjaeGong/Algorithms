#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a,b,n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;++i)
        cin >> arr[i];
    sort(arr,arr+n);
    a = max(arr[n-1]*arr[n-2], arr[0]*arr[1]); // 모든 경우에 대해서 최대값을 찾음
    b = max(arr[0]*arr[1]*arr[n-1], arr[n-1]*arr[n-2]*arr[n-3]);
    cout << max(a,b);
}
