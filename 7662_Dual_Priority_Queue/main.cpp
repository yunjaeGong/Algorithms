#include <cstdio>
#include <queue>
#include <cstring>

#define pii pair<int,int>
#define s second
#define f first
using namespace std;
int main() {
    int N, T, num;
    char inp[2];
    scanf("%d", &T);
    while(T--) {
        priority_queue<pii> M_Q;
        priority_queue<pii,vector<pii>,greater<>> m_Q;
        scanf("%d", &N);
        bool *valid = new bool [N+1];
        memset(valid, 0, N);
        for(int i=0;i<N;++i) {
            scanf("%s", inp);
            scanf("%d", &num);
            switch(inp[0]) {
                case 'I': M_Q.push({num, i}); m_Q.push({num, i}); valid[i] = true; break;
                case 'D':
                    if(num == -1)
                        while(!m_Q.empty()) {
                            if(valid[m_Q.top().s]) { // 유효하면
                                valid[m_Q.top().s] = false; // 유효하지 않다 표시
                                break; // 명령 완료
                            }
                            m_Q.pop(); // Max heap에서 지운(유효하지 않은 수 삭제)
                        }
                    else
                        while(!M_Q.empty()) {
                            if(valid[M_Q.top().s]) { // 유효하면
                                valid[M_Q.top().s] = false; // 유효하지 않다 표시
                                break; // 명령 완료
                            }
                            M_Q.pop(); // min heap에서 지운(유효하지 않은 수 삭제)
                        }
                    break;
            }
        }
        while(!m_Q.empty() && !valid[m_Q.top().s])
            m_Q.pop();
        while(!M_Q.empty() && !valid[M_Q.top().s])
            M_Q.pop();

        if(m_Q.empty() || M_Q.empty())
            printf("EMPTY\n");
        else
            printf("%d %d\n", M_Q.top().f, m_Q.top().f);
        delete[] valid;
    } // end of while
}