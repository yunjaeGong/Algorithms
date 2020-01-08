#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    short in[4];
    for(int i=0;i<4;++i)
        cin >> in[i];
    sort(in, in+4);
    cout << min(in[0], in[1]) * min(in[2], in[3]);
}
