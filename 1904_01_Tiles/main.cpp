#include <iostream>
int N, MAX = 1000000;
int main() {
    std::cin >> N;
    auto *dp = new unsigned int[MAX];
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=MAX;++i) {
        dp[i] = (dp[i-1] + dp[i-2])%15746;
    }
    std::cout << dp[N];
}
