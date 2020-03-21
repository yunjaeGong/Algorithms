#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, w, L, tail = 0, B_w, cnt = 0, head = 0;
    scanf("%d %d %d",&n,&L,&w);
    int truck_w[n];
    queue<int> B;
    B_w = w;
    for(int i=0;i<n;++i)
        scanf("%d",&truck_w[i]);
    while(head < n) {
        if(head < n && !B.empty() && B.front()==cnt) { // 빼기
            B.pop();
            B_w += truck_w[head];
            head++;
        }
        if(tail<n && B_w >= truck_w[tail] && B.size() <= L) {
            B.push(cnt+L);
            B_w -= truck_w[tail];
            tail++;
        }
        cnt++;
    }
    cout << cnt;
}