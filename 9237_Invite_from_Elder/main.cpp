#include <iostream>
#include <algorithm>
using namespace std;
int N, Max = 0;
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int *a = new int[N];
    for(int i=0;i<N;++i)
        cin >> a[i];
    sort(a,a+N,greater<>());
    for(int i=0;i<N;++i)
        Max = max(Max, i+a[i]+2);
    cout << Max;
}
