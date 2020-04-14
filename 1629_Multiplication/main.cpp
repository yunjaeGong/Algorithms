#include <iostream>
int A, C;
long long pow(int B) {
    if(B==1)
        return A%C;
    long long tmp = pow(B/2);
    if(B%2) // B가 홀수이면
        return ((tmp * tmp)%C * A)%C;
    else
        return (tmp * tmp)%C;
}
int main() {
    int B;
    std::cin >> A >> B >> C;
    std::cout << pow(B)%C;
}
