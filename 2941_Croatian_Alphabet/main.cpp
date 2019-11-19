#include <iostream>
#include <string>
using namespace std;
int main() {
    int i=0, cnt=0;
    string s;
    cin >> s;
    for(;i<s.size();++i) {
        switch(s[i]) {
            case 'd':
                if(s[i+1] == '-') i++;
                else if(s[i+1] == 'z' && s[i+2] == '=') i+=2;
                break;
            case 'c':
                if(s[i+1] == '=' || s[i+1] == '-') i++;
                break;
            case 'l':
            case 'n':
                if(s[i+1] == 'j') i++;
                break;
            case 's':
            case 'z':
                if(s[i+1] == '=') i++;
                break;
        }
        cnt++;
    }
    cout << cnt;
}