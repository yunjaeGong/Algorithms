#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, w, L, head = 0, B_w, cnt = 1, tail = 0;
    scanf("%d %d %d",&n,&L,&w);
    int truck_w[n];
    queue<int> B;
    B_w = w;
    for(int i=0;i<n;++i)
        scanf("%d",&truck_w[i]);
    while(tail<n) {
        while (tail < n && B_w >= truck_w[tail]) { //
            if (!B.empty() && B.front() == cnt) { // head 트럭 다리 통화하면
                B.pop(); // 다리 위 트럭에서 통과한 트럭 삭제
                B_w += truck_w[head]; // 다리 하중에서 뺌
                head++;
            }
            B_w -= truck_w[tail]; // 다음 트럭 다리 위로
            tail++;
            B.push(cnt + L);
            cnt++; // 시간
        }
        while (head < n && (B_w < truck_w[tail] && !B.empty())) {
            cnt += B.front() - cnt;
            B_w += truck_w[head];
            head++;
            B.pop();
        }
    }
    for(int i=0,j=0;j<n;++i ) {

    }
    cout << cnt;
}