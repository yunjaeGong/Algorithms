#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int h;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h;
    int nodes = pow(2, h+1) - 1;
    int edges = nodes - 1;
    int *e = new int[edges+1]; // 에지 가중치
    int *dp = new int[edges+1]; // 누적합

    memset(e, 0, sizeof(int)*(edges+1));
    memset(dp, 0, sizeof(int)*(edges+1));
    // 1부터 시작
    for(int i=1;i<=edges;++i)
        cin >> e[i]; // 루트(1)의

    for(int i=nodes/2;i>0;--i) {
        int L = 2*i-1, R = 2*i, LL = 4*i-1, RR = 4*i+2; // edge
        int nL = 2*i, nR = 2*i+1; // node
        if(LL > edges)
            LL = 0;
        if(RR > edges)
            RR = 0;
        if(e[L] + e[LL] > e[R] + e[RR]) { // 왼쪽 높이가 길면
            e[R] += (e[L] + e[LL]) - (e[R] + e[RR]); // 오른쪽 현 엣지 길이 증가
        } else if(e[L] + e[LL] < e[R] + e[RR]) {
            e[L] += (e[R] + e[RR]) - (e[L] + e[LL]);
        }
        dp[i] = dp[nL] + dp[nR] + e[L] + e[R]; // dp 업데이트
        e[L] += e[LL];
        e[R] += e[RR];
    }

    cout << dp[1];
}
