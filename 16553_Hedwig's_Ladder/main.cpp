#include <iostream>
const int MOD = 10007;
int main() {
    int T;
    std::cin >> T;

    long long f[1001];
    f[1] = 2, f[2] = 3;
    for(int i=3;i<=1000;++i) {
        f[i] = f[i-1]%MOD + f[i-2]%MOD + i%2;
    }
    for(int k=0;k<T;++k) {
        int i, n;
        scanf("%d%d", &n, &i);
        printf("%d %lld\n", n, f[i]%MOD);
    }
}