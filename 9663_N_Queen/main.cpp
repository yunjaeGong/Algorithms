#include <cstdio>
#include <vector>

using namespace std;
int N, cnt=0;
struct P {int x, y;};
bool possible(vector<P> &pos, int x) { // pos[i] = i level에 있는 퀸의 위치
    for(int diagonal = 1, i = pos.size()-1;i>=0;--i,++diagonal) {
        if(pos[i].x == x) return false;
        if((pos[i].x == x+diagonal) || pos[i].x == x-diagonal)
            return false;
    }

    return true;
}
int dfs(vector<P> &pos, int x, int y) {
    if(y>=N-1) return cnt+=1;
    for(int i=0;i<N;++i) {
        if(possible(pos,i)) { // 다음 레벨의 i위치에 놓는게 가능하면
            pos.push_back({i,y+1}); // 다음 level에 퀸 추가
            dfs(pos, i, y+1);
            pos.pop_back(); // back track
        }// 다음 자리에 가능하면
    }
    return 0;
}
int main() {
    scanf("%d",&N);
    for(int i=0;i<N;++i) {
        vector<P> pos;
        pos.push_back({i,0});
        dfs(pos,i,0);
    }
    printf("%d",cnt);
    return 0;
}