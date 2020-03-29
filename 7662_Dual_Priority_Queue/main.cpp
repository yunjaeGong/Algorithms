#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N, T, num;
    char inp[2];
    cin >> T;
    while(T--) {
        priority_queue<int,vector<int>> M_Q;
        priority_queue<int,vector<int>,greater<>> m_Q;
        cin >> N;
        for(int i=0;i<N;++i) {
            cin >> inp >> num;
            switch(inp[0]) {
                case 'I': M_Q.push(num); m_Q.push(num); break;
                case 'D':
                    if (num == -1) { // 최솟값
                        if(!m_Q.empty())
                            m_Q.pop();
                    } else { // 최댓값
                        if(!M_Q.empty())
                            M_Q.pop();
                    }
                    break;
            }
        }
        if(m_Q.size() + M_Q.size() == N)
            printf("EMPTY\n");
        else
            printf("%d %d\n",m_Q.top(), M_Q.top());
    } // end of while
}
