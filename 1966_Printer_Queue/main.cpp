#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int T,N,M,x,pos;
int main() {
    scanf("%d", &T);
    while (T--) {
        pos = 0;
        queue<pair<int, int>> Q;
        priority_queue<int> pq;
        scanf("%d%d", &N, &M);
        for (int i=0;i<N;i++) {
            scanf("%d", &x);
            Q.push({x,i});
            pq.push(x);
        }
        while (!Q.empty()) {
            int num = Q.front().first;
            int P = Q.front().second;
            Q.pop();
            if (pq.top() == num) { // 가장 큰 값이 num이면
                pos++;
                pq.pop();
                if (P == M) break;
            }
            else Q.push({num,P});
        }
        printf("%d\n", pos);
    }
}