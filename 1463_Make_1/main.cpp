#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int i = N-1;
    int *a = new int[N+1];
    a[N] = 0;
    while(i > 0) {
        if(3*i<=N)
            a[i] = min(a[3*i],min(a[2*i],a[i+1])) + 1;
        else if(2*i<=N)
            a[i] = min(a[2*i],a[i+1]) + 1;
        else
            a[i] = a[i+1] + 1;
        i--;
    }
    cout << a[1];
    return 0;
}