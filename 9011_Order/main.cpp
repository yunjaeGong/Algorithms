#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while(T) {
        bool P = true;
        cin >> n;
        int r[n], s[n]; // r[]: (자신)s[i]보다 작은수의 개수 저장, s[i] r[]로부터 복원한 수열
        vector<int> A(n); // 서로 다른 n개의 중복없는 정수 저장 (s[i] 후보)
        for(int i=0;i<n;++i) {
            A[i] = i+1; cin >> r[i];
        }
        for(int i=n-1;i>=0;--i) { // 뒤에서부터
            if(r[i]>i || r[i]>=A.size()) {
                cout << "IMPOSSIBLE" << endl;
                P = false; break;
            }
            s[i] = A[r[i]]; //
            A.erase(A.begin()+r[i]);
        }
        if(P) {
            for(int i=0;i<n;++i)
                cout << s[i] << " ";
            cout << endl;
        }
        T--;
    }
}