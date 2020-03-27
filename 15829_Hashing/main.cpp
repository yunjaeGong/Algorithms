#include <iostream>
#include <string>
using namespace std;
int M = 1234567891;
unsigned long long sq[51], res;
int main() {
    string s;
    int len;
    cin >> len;
    cin >> s;
    sq[0]=1;
    for(int i=1;i<50;++i)
        sq[i] = (sq[i-1]*31)%M;
    for(int i=0;i<len;++i)
        res = (res + ((s[i]-'a'+1)*sq[i])%M)%M;
    cout << res;
}
