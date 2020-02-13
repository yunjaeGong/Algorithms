#include <iostream>

using namespace std;

int main() {
    int rot = 1, a, b, s, N, dir = 0;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> a >> b >> s;
        if(s == 1)
            dir = 1 - dir;
        rot = (rot / a) * b;
    }
    cout << dir << " " << rot;
}