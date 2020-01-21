#include <iostream>
int N;
unsigned int f[21];
int main() {
    std::cin >> N;
    f[1] = 1;
    for(int i=2;i<=N;++i)
        f[i] = f[i-1] + f[i-2];
    std::cout << f[N];
}