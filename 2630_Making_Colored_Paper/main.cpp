#include <iostream>
using namespace std;
short paper[129][129];
int wb[2]; // white blue
void make(int s_x, int s_y, int t_x, int t_y, int s) {
    int m_x = (s_x + t_x)/2, m_y = (s_y + t_y)/2;
    bool if_brk=false;
    int col = paper[s_y][s_x];
    for(int i=s_y;i<=t_y;++i) {
        for(int j=s_x;j<=t_x;++j)
            if(paper[i][j] != col) {
                if_brk = true;
                break;
            }
        if(if_brk)
            break;
    }
    if(!if_brk) {  // 모든 칸이 같은 색이면
        wb[col]++;
        if(s==1)
            return;
    }
    make(s_x, s_y, m_x, m_y, s/2);
    make(m_x+1, s_y, t_x, m_y, s/2);
    make(s_x, m_y+1, m_x, t_y, s/2);
    make(m_x+1, m_y+1, t_x, t_y, s/2);
}

int main() {
    short N, tf;
    scanf("%hd",&N);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j) {
            scanf("%hd",&tf);
            paper[i][j] = tf;
        }
    make(0,0,N-1,N-1,N);
    printf("%d\n%d", wb[0], wb[1]);
}
