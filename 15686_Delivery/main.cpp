#include <iostream>
#include <vector>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
int N, M, res;
short map[50][50];
vector<pii> c, h, selected;
bool visited[13];
int dist(pii &a, pii &b) {
    int y = a.f-b.f, x = a.s-b.s;
    return  y<0?-y:y + x<0?-x:x;
}
int calc() {
    int sum = 0;
    for(int i=0;i<h.size();++i) {
        int d = 1<<30;
        for(int j=0;j<c.size();++j) {
            d = min(d, dist(h[i], c[j]));
        }
        sum += d;
    }
}

void select(int idx, int cnt) {
    if(cnt >= M) { // 최대 M개 -> M개 다 쓰면 최소
        res = min(res, calc());
    }
    for(int i=idx;i<c.size();++i) {
        if(visited[i]) continue;
        visited[i] = true;
        select(i+1, cnt+1);
        visited[i] = false;
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
}
