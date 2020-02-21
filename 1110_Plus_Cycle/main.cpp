#include <iostream>
#include <string>
using namespace std;
string in;
int calc(string a, int cnt) {
    if(a.length()<2)
        a += "0";
    if(a==in && cnt>0)
        return cnt;
    return calc(to_string(stoi(to_string(stoi(a)%10) + to_string((((char)a[0] + (char)a[1])-'0'*2)%10))), cnt+1);
}

int main() {
    cin >> in;
    cout << calc(in, 0);
}
