#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    for (int i=1;i<=N;++i) {
        cin >> s;
        cout << "String #" << i << "\n";
        for (int j = 0; j < s.length(); ++j) {
            cout << (char)((s[j] - 'A' + 1) % 26 + 'A');
        }
        cout << "\n\n";
    }
}