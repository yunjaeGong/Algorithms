#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> v;
bool check[8];
int nums[8];

void permu(int dep){
    if (dep == M){
        for (int i=0;i<M;++i) printf("%d ", nums[i]);
        printf("\n");
        return;
    }
    bool used[10001] {false};
    for (int i=0; i<v.size(); ++i){
        if (used[v[i]] || check[i]) continue;
        used[v[i]] = true;
        nums[dep] = v[i];
        check[i] = true;
        permu(dep + 1);
        check[i] = false;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int val;
    for (int i=0; i<N; ++i) {
        scanf("%d", &val);
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    permu(0);
    return 0;
}