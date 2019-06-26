#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char s[101];
    char a[26];
    memset(a,0,26);
    fgets(s,101,stdin);
    for(int i=0;i<strlen(s);++i)
        a[s[i]-'a'] += 1;
    for(int i=0;i<26;++i)
        printf("%d ",a[i]);
}