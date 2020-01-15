#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
void suffix(string &s, int len) {
    if(len <= 0) return ;
    string tmp = s.substr(1,len-1);
    v.emplace_back(s);
    suffix(tmp, len-1);
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    suffix(s, s.length());
    sort(v.begin(), v.end());
    for(string e:v)
        cout << e << endl;
}
