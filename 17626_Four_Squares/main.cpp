#include <iostream>
#include <vector>
using namespace std;
const int MAX = 50001;
short DP[MAX];
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=1;i<230;++i)
        v.push_back(i*i);
    DP[1] = 1;
    for(int i=2;i<n;++i) {
        int new_min = 1<<30;
        for(int j=0;v[j]<=i;++j) { // i를 생성

            
            DP[i] = min(DP[i], new_min);
        }
    }

}
