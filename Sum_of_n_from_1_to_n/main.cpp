#include <iostream>
using namespace std;
long long sum = 1;

long long sum_of_i(int i) {
    if(i == 1) return 1;
    return (sum += sum_of_i(i-1));
}

int main() {
    int n;
    cin >> n;

    sum_of_i(n);
    cout << sum;
}
