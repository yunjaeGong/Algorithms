#include <iostream>
using namespace std;
int N, r, c, cnt, mul;
void calc(int s_x, int s_y, int t_x, int t_y, int n) {
    int m_y = (s_y+t_y)/2, m_x = (s_x+t_x)/2;
    if(c<m_x) {
        if(r<m_y) // 1사분면
            mul = 0, t_x = m_x, t_y = m_y;
        else // 3사분면
            mul = 2, s_y = m_y+1, t_x = m_x;
    }
    else {
        if(r<m_y) // 2사분면
            mul = 1, s_x = m_x+1, t_y = m_y;
        else // 4사분면
            mul = 3, s_x = m_x+1, s_y = m_y+1;
    }
    n--;
    cnt+= mul*(1<<n)*(1<<n); // (r,c)가 존재하지 않는(탐색하지 않는) 격자들의 '넓이'/순서
    // mul 변수는 탐색하지 않고 지나치는 사분면의 수
    if(n<=0) { // 1x1 격자이면
        cout << cnt;
        return;
    }
    calc(s_x, s_y, t_x, t_y, n); // 시작 (r,c), 끝 (r,c)
}
int main() {
    cin >> N >> r >> c;
    int S = (1<<N);
    calc(0,0,S,S,N);
}
