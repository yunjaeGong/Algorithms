#include <iostream>

using namespace std;

int res = 50;
string str1, str2;

int main() {
    cin >> str1 >> str2;
    for(int d=0; d<=str2.length()-str1.length(); ++d) {
        int dist = 0;
        for(int i=0; i<str1.length(); i++)
            if(str1[i] != str2[i+d]) dist++;
        res = min(res, dist);
    }
    cout << res;
}
