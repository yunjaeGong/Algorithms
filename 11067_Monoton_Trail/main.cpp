#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> Pair;
int main() {
    int times, n, m;
    cin >> times;
    while(times) {
        cin >> n;
        Pair* arr = new Pair[n];
        Pair* result = new Pair[n];
        for(int i=0;i<n;++i)
            cin >> arr[i].first >> arr[i].second;
        cin >> m;
        int m_arr[10];
        for(int i=0;i<m;++i)
            cin >> m_arr[i];

        Pair curr=arr[0], next, closest_pair;

        times--;
    }
}