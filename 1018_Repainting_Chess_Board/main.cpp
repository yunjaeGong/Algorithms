#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string board[50];
string wFirst[8] = {
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" }
};
string bFirst[8] = {
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" },
        { "BWBWBWBW" },
        { "WBWBWBWB" }
};
using namespace std;
int N, M;

int WBCnt(int y, int x, bool w) {
    int cnt = 0;
    for(int i=y;i<y+8;i++)
        for(int j=x;j<x+8;j++)
            if((w && board[i][j] == wFirst[i-y][j-x]) || (!w && board[i][j] == bFirst[i-y][j-x]))
                cnt++;
    return cnt;
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0;i<N;++i)
        cin >> board[i];

    int res=1<<30;
    for(int i=0;i+7<N;i++)
        for(int j=0;j+7<M;j++)
            res = min(res, min(WBCnt(i, j, true), WBCnt(i, j, false)));
    cout << res;
}
