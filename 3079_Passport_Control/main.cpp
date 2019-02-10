#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool c(pair<long long, int> a,pair<long long, int> b) { return a.first+a.second>b.first + b.second; }
int main() {
    int N, M;
    cin >> N >> M;
    //M은 학생 수
    vector<pair<long long,int>> fin_t(N);
    for(int i=0;i<N;++i)
        cin >> fin_t[i].second;
    make_heap(fin_t.begin(),fin_t.end(),c);
    while(M) {
        pair<long long, int> tmp = fin_t.front(); // 최소
        // 업데이트 후 재정렬
        fin_t.front().first += fin_t.front().second;
        /*for(int i=0;i<N;++i)
            cout << fin_t[i].first << " ";
        cout << endl;*/
        make_heap(fin_t.begin(),fin_t.end(),c);
        /*for(int i=0;i<N;++i)
            cout << fin_t[i].first << " ";
        cout << endl;*/
        M--;
    }
    long long max = fin_t.front().first;
    for(int i=0;i<N;++i)
        if(fin_t[i].first<max)
            max = fin_t[i].first;
    /*for(int i=0;i<N;++i)
        cout << fin_t[i].first << " ";
    cout << endl;*/
    cout << max;
    return 0;
}
// MNlogn?
