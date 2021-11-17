#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
int a[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> L;
    for(int i=0;i<n;++i)
        cin >> a[i];

    int cnt=0, head=0, tail=0;
    int W = L;
    queue<int> B;
    while(head < n) {
        // 다리에서 빼기
        if(head < n && B.size() && B.front() == cnt) {
            B.pop();
            W += a[head];
            head++;
        }

        // 다리에 넣기
        if(tail < n && W >= a[tail] && B.size() <= L) {
            B.push(cnt + w);
            W -= a[tail];
            tail++;
        }
        cnt++;
    }
    cout << cnt;
}
