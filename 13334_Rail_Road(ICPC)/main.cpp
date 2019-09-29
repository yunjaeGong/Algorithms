#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
struct Compare {
    constexpr bool operator()(pair<int, int> const & a,
                              pair<int, int> const & b)
    { return a.second > b.second; }
};
bool comp(const pii &a, const pii &b) { return a.second < b.second; }
int main() {
    int N, h, o, d, max = 0;
    scanf("%d",&N);
    vector<pair<int,int>> inp;
    vector<pair<int,int>> cut;
    for(int i=0;i<N;++i) {
        scanf("%d%d",&h,&o);
        inp.push_back({h,o});
    }
    scanf("%d",&d);
    for(int i=0;i<N;++i) {
        h=inp[i].first, o = inp[i].second;
        if(h>o?h-o:o-h <= d) {
            if(h<o)
                cut.push_back({h,o});
            else
                cut.push_back({o,h});
        }
    }
    sort(cut.begin(), cut.end(), comp);
    priority_queue<int,vector<int>,greater<>> SQ;
    for(int i=0;i<cut.size();++i) {
        SQ.push(cut[i].first);
        while(!SQ.empty() && SQ.top() < cut[i].second - d)
            SQ.pop();
        int size = SQ.size();
        if(max < size)
            max = size;
    }
    printf("%d",max);
}