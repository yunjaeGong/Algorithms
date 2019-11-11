#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    int i = 0;
    char temp;
    cin >> a;
    i = a[i]^'C';
    for (int j = 0; j < a.size(); j++) {
        temp = a[j] ^ i;
        cout << temp;
    }
}