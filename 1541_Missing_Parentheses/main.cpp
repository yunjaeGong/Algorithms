#include <cstdio>
#include <cstring>
int main() {
    char a[51];
    scanf("%s",a);
    int j=1,tmp=0,sum=0,total=0;
    for(int i=strlen(a)-1;i>=0;--i) {
        if(a[i] != '+'&&a[i] != '-') {
            tmp += (a[i]-'0')*j;
            j*=10;
        } else {
            sum += tmp;
            tmp=0;
            j=1;
            if(a[i]=='-') {
                total -= sum;
                sum=0;
            }
        }
    }
    total += tmp+sum;
    printf("%d",total);
}