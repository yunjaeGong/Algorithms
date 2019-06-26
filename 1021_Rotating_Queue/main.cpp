#include <iostream>
#include <deque>
#include <math.h>
using namespace std;
int find(deque<int> &Q, int can);
int main() {
    int N, M, in, idx, can, n_head, cnt=0;
    scanf("%d%d", &N, &M);
    deque<int> Q;
    for (int i = 0; i < N; ++i) {
        Q.push_back(i+1);
    }

    for(int i=0;i<M;++i) {
        scanf("%d", &can);
        idx = find(Q,can);
        n_head = Q[idx]; // 새 헤드
        if(idx == -1) fprintf(stderr,"not found\n");
        if(idx < Q.size() - idx) { // right < left
            while(Q.front() != n_head) {
                Q.push_back(Q.front());
                Q.pop_front();
                cnt++;
            }
        } else {
            while(Q.front() != n_head) {
                Q.push_front(Q.back());
                Q.pop_back();
                cnt++;
            }
        }
        Q.pop_front();
    }
    cout << cnt;
}
inline int find(deque<int> &Q, int can) {
    for(int i=0;i<Q.size();++i) {
        if(Q[i] == can)
            return i;
        }
    return -1;
}