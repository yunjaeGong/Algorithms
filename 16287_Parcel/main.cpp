#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, pair<int, int>> P;
bool comp(P a, P b) { return a.first<b.first; }
int main() {
    int W, N;
    cin >> W >> N;
    int *arr = new int[N];
    vector<P> v;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j)
            v.push_back({arr[i] + arr[j], {i, j}}); // 2개의 합을 만듬
    //int left = 0, right = N - 1;
    sort(v.begin(), v.end(),comp); // 오름차순 정렬
    // 4개의 합 찾기
    /*while (left != right) { // 양 끝을 줄여나가는 방식
        int candidate = v[left].first + v[right].first
        if (sum == W) {
            set<int> s = {v[left].second.first, v[left].second.second,v[right].second.first,v[right].second.second};
            if(s.size() == 4) {
                cout << "YES";
                return 0;
            }
            left++;
        }
        else if (sum > W)
            right--;
        else if(sum < W)
            left++;
    }*/
    for (P p : v) { // v의 원소 p에 대해
        vector<P>::iterator it = lower_bound(v.begin(), v.end(), P(W - p.first, {-1, -1})); // W - p.first를 벡터 v에서 찾는다
        while (it != v.end() && p.first + (*it).first == W) {
            set<int> s = {it->second.first, it->second.second,p.second.first,p.second.second};
            if(s.size() == 4) { cout << "YES";return 0; }
            ++it;
        }
    }
    cout << "NO";
}