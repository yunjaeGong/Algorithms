#include <cstdio>
#include <cstring>
int main() {
    char a[11],count[11];
    scanf("%s",a);
    memset(count,0,10);
    for(int i=0;i<strlen(a);++i)
        ++count[a[i]-'0']; // counting sort 이용
    for(int i=9;i>=0;--i)
        while(count[i]--) printf("%d",i);
}