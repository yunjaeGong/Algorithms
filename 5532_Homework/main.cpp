#include <iostream>
int L,A,B,C,D;
int main() {
    std::cin >> L >> A >> B >> C >> D;
    std::cout << L - std::max(A/C + (A%C?1:0),B/D + (B%D?1:0));
}
