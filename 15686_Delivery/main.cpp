#include <iostream>
#include <vector>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
int N, M, res;
short map[50][50];
bool visited[13];
vector<pii> c, h, selected;
int dist(pii &a, pii &b) { return abs(a.f-b.f) + abs(a.s-b.s); }
int calc() {
    int sum = 0;
    for(pii home:h) {
        int d = 1<<30;
        for(pii sel:selected) {
            d = min(d, dist(home, sel));
        }
        sum += d;
    }
    return sum;
}

void select(int idx, int cnt) {
    if(cnt >= M) { // 최대 M개 -> M개 다 쓰면 최소
        res = min(res, calc());
        return;
    }
    for(int i=idx;i<c.size();++i) {
        if(visited[i]) continue;
        visited[i] = true;
        selected.push_back(c[i]);
        select(i+1, cnt+1);
        visited[i] = false;
        selected.pop_back();
    }
}

int main() {
    cin >> N >> M;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            cin >> map[i][j];
            if(map[i][j] == 1)
                h.emplace_back(i,j);
            else if(map[i][j] == 2)
                c.emplace_back(i,j);
        }
    }

    res = 1<<30;
    select(0, 0);
    cout << res;
}
