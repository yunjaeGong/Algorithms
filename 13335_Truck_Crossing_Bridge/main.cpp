#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, w, L, i = 0, B_w, cnt = 1, j = 0;
    scanf("%d %d %d",&n,&L,&w);
    int truck_w[n];
    queue<int> B;
    B_w = w;
    for(int i=0;i<n;++i)
        scanf("%d",&truck_w[i]);
    while(j<n) {
        while(i<n && B_w >= truck_w[i] && (!B.empty() && B.front() != cnt)) { //
            B_w -= truck_w[i];
            i++;
            B.push(cnt+L);
            cnt++;
        }
        while(j<n && (B_w < truck_w[i] && !B.empty())) {
            cnt += B.front()-cnt;
            B_w += truck_w[j];
            j++;
            B.pop();
        }
    }
    cout << cnt;
}