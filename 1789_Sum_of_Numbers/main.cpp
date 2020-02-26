#include <iostream>

int main() {
    long long in, prev=0, N=0;
    std::cin >> in;
    for(int i=1;prev<in;++i, prev+=i)
        N++;
    std::cout << N;
}
