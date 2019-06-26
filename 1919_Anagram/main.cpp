#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char a[1001], b[1001];
    scanf("%s%s",a, b);
    int a_l = strlen(a),b_l = strlen(b);
    int c[26] = {0}, d[26] = {0}, res = 0;
    for(int i=0; i<a_l; i++)
        c[a[i]-'a']++;
    for(int i=0; i<b_l; i++)
        d[b[i]-'a']++;
    for(int i=0; i<26; i++) res += abs(c[i] - d[i]);
    printf("%d",res);
}