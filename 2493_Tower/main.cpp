#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, in;
    deque<int> process;
    vector<int> res;
    scanf("%d",&n);
    stack<pair<int,int>> s; // stack을 앞에 걸릴 후보들로 사용
    for(int i=1;i<=n;++i) {
        scanf("%d",&in); // 높이 입력
        while(!s.empty()) {
            if(s.top().second > in) {
                printf("%d ",s.top().first);
                break;
            }
            s.pop();
        }
        if(s.empty()) printf("0 ");
        s.push(make_pair(i,in));
    }
}