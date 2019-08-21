#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M, tmp;
    scanf("%d", &N);
    vector<int> have;
    for (int i=0;i<N;++i) {
        scanf("%d",&tmp);
        have.push_back(tmp);
    }
    sort(have.begin(), have.end());
    scanf("%d",&M);
    for(int i=0;i<M;++i) {
        scanf("%d", &tmp);
        if (binary_search(have.begin(), have.end(), tmp))
            printf("1 ");
        else
            printf("0 ");
    }
}