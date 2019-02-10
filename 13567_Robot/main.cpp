#include <iostream>
#include <utility>
#include <string>
using namespace std;
typedef pair<int,int> Pair;
Pair Dir[4] = { make_pair(1,0), make_pair(0,1), make_pair(-1,0), make_pair(0,-1) }; // 오름차순: 0, 내림차순: 1
int m, n;
void turn(Pair& pr, int in, int& d) {
    if(in == 0)
        d = (d+1)%4;
    else
        d = (d-1)<0?3:(d-1);
}
bool inside(Pair& pr) { return pr.first < m && pr.second < m && pr.first >= 0 && pr.second >= 0; }
int main() {
    cin >> m >> n;
    string str;
    int in, d = 0;
    Pair coordinate = { make_pair(0,0) };
    for(int i=0;i<n;++i) {
        // 격자 내에 있는지 체크
        cin >> str >> in;
        if(str == "MOVE") {
            coordinate.first += Dir[d].first*in;
            coordinate.second += Dir[d].second*in;
        }
        else
            turn(coordinate,in,d);
        if(!inside(coordinate)) {
            cout << -1; return 0;
        }
    }
    cout << coordinate.first << " " << coordinate.second;
    return 0;
}