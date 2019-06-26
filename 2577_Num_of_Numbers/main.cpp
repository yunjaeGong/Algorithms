#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main() {
    int A,B,C;
    char b[10];
    memset(b,0,10);
    scanf("%d%d%d",&A,&B,&C);
    string a = to_string(A*B*C);
    for(int i=0;i<a.length();++i)
        b[a[i]-'0'] += 1;
    for(int i=0;i<10;++i)
        printf("%d\n",b[i]);
}