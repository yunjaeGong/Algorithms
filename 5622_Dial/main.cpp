#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    int size = str.length(), num = 0;
    for(int i=0;i<size;++i) {
        if(str[i]<'D')
            num += 3;
        else if(str[i]<'G')
            num += 4;
        else if(str[i]<'J')
            num += 5;
        else if(str[i]<'M')
            num += 6;
        else if(str[i]<'P')
            num += 7;
        else if(str[i]<'T')
            num += 8;
        else if(str[i]<'W')
            num += 9;
        else
            num += 10;
    }
    cout << num;
}
