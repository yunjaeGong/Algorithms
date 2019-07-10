#include <cstdio>
#include <cstdlib>
#include <cstring>
int main() {
    while(1) {
        int n=0;
        char a[11];
        scanf("%s",a);
        if(strlen(a)==1) n=a[0]-'0';
        while(strlen(a)!=1) {
            n=0;
            for(int i=strlen(a)-1;i>=0;--i)
                n+= a[i]-'0';
            sprintf(a,"%d",n);
        }
        if(n==0) break;
        printf("%d\n",n);
    }
}