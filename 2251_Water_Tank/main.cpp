#include <iostream>
#include <queue>
#include <set>
using namespace std;
int Max[3], B[3];
int main() {
    cin >> Max[0] >> Max[1] >> Max[2];
    queue<int> Q;
    set<int> res;
    bool visited[3][201];
    Q.push(2);
    res.insert(Max[2]);
    B[2] = Max[2];
    while(!Q.empty()) {
        int idx = Q.front();
        Q.pop();
        for(int i=0;i<3;++i)
            if(B[i] < Max[i] && i != idx) {
                int tmp = min(Max[i] - B[i], B[idx]);
                if(visited[2][B[i] + tmp])
                    continue;
                B[i] += tmp;
                B[idx] -= tmp;
                visited[i][B[i]] = true;
                if(idx == 2)
                    res.insert(B[idx] - tmp);
                else if(i == 2)
                    res.insert(B[i]);
                Q.push(i);
            }
    }
    for(int e:res)
        cout << e << " ";
}
