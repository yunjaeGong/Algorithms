#include <iostream>
using namespace std;
int res[100001], v[101], w[101];
int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for(int i=0;i<N;++i)
        cin >> w[i] >> v[i];

    for(int i=0;i<N;++i) { // i번 객체에 대해
        for(int j=K;w[i]<=j;--j) { // 조건덕에 같은 객체가 여러번 담기지 않음
            res[j] = max(res[j], res[j-w[i]] + v[i]);
        }
    }
    cout << res[K];
}