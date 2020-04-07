#include <iostream>
using namespace std;
int N;
char f[50][51];
int cnt[51];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0;i<N;++i)
        cin >> f[i];
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j) {
            if(f[i][j] == 'Y') {
                cnt[i]++;
                cnt[j]++;
            } // i는 j의 2친구
            else {
                for(int k=0;k<N;++k) { // 공통친구 찾기
                    if(k == i || k == j)
                        continue;
                    if(f[i][k] == f[j][k] && f[i][k] == 'Y') { // 공통친구 존재하면 표시하고 break;
                        cnt[i]++;
                        cnt[j]++;
                        break;
                    }
                }
            }
        }
    }
    int Max = 0;
    for(int i=0;i<N;++i)
        Max = max(Max,cnt[i]);
    cout << Max;
}