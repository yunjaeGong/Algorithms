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
        for(int i=n-1;i>=0;--i) { // 마지막 원소부터 탐색
            if(r[i]>i || r[i]>=A.size()) { // 수열을 만들 수 없으면
                // ( 내(s[i])앞에 너무 많은 수가 필요할 때 -> r[i]>i 혹은 s[i] 후보 (A[]) 의 최댓값보다 더 많은 수가 (s[i]>n인 경우) 필요할 때
                cout << "IMPOSSIBLE" << endl;
                P = false; break;
            }
            s[i] = A[r[i]]; // r[i]는 A(s[i]의 후보) 중 r[i] 조건을 만족하는 s[i]의 위치
            A.erase(A.begin()+r[i]); // 사용한 s[i]는 제거 (중복 x)
        }
        if(P) { // 수열을 만들 수 있으면
            for(int i=0;i<n;++i)
                cout << s[i] << " ";
            cout << endl;
        }
        T--;
    }
}