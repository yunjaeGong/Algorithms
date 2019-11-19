#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;
    for(int a=1;a<=1000000;++a) {
        int sum = a, tmp = a;
        while(tmp!=0) {
            sum += (tmp%10);
            tmp/=10;
        }
        if(sum == N) {
            std::cout << a;
            return 0;
        }
    }
    std::cout << 0;
}