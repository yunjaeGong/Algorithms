#include <cstdio>
#include <vector>
#include <algorithm>
int N;
int main() {
    scanf("%d",&N);
    int data;
    std::vector<int> LIS;
    scanf("%d",&data);
    LIS.push_back(data);
    for(int i=1;i<N;++i) {
        if(data > LIS.back())
            LIS.push_back(data);
        else {
            auto it = lower_bound(LIS.begin(), LIS.end(), data);
            if(it != LIS.end()) *it = data;
        }
    }
    printf("%d",LIS.size());
}