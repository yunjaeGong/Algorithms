#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
    int n, num[10]={0},max=0;
    scanf("%d",&n);
    string s = to_string(n);
    for(int i=0;i<s.size();++i) {
        num[s[i]-'0']++;
    }
    max = ceil((num[6] + num[9])/2.0);
    for(int i=0;i<10;++i) {
        if(num[i] > max && i!= 6 && i!=9) max = num[i];
    }
    cout << max;
}