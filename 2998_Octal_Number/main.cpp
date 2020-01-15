#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string s, res, str;
char to_oct(string &str) {
    int ret;
    switch(stoi(str)) {
        case 0: ret = 0; break;
        case 1: ret = 1; break;
        case 10: ret = 2; break;
        case 11: ret = 3; break;
        case 100: ret = 4; break;
        case 101: ret = 5; break;
        case 110: ret = 6; break;
        case 111: ret = 7; break;
    }
    return '0'+ret;
}

int main() {
    cin >> s;
    int len = s.length(), i;
    for(i=len;i>2;i-=3) {
        str = s.substr(i-3,3);
        res += to_oct(str);
    }
    if(i) {
        str = s.substr(0, i);
        res += to_oct(str);
    }
    reverse(res.begin(), res.end());
    cout << res;
}
