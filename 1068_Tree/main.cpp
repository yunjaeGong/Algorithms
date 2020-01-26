#include <iostream>
using namespace std;
int N, P[50], idg[50];
int main() {
    int root, del, leaf = 0;
    cin >> N;
    for(int i=0;i<N;++i) {
        cin >> P[i];
        if(P[i] == -1) root = i;
        else idg[P[i]]++;
    }
    // 진입분지수 카운트
    cin >> del;
    idg[P[del]]--;
    for(int i=0;i<N;++i) {
        if(idg[i] || i == del) continue; // 진입분지 있으면 일단 패스
        leaf++;
        int cur = i;
        while(P[cur] != -1) {
            if(P[cur] == del) {
                leaf--; break;
            }
            cur = P[cur];
        }
    }
    cout << leaf;
}
