#include<iostream>
using namespace std;
int A[1000001], MIN = 1000001, MAX = -1000001, N;
int main() {
    cin.tie(NULL), ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> A[i];
        MIN = min(MIN, A[i]);
        MAX = max(MAX, A[i]);
    }
    cout << MIN << ' ' << MAX;
}