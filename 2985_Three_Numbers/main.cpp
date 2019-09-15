#include <cstdio>

int main() {
    int a[3];
    float res;
    scanf("%d%d%d",&a[0], &a[1], &a[2]);
    char op[] = {'*','/','+','-'};
    for(int i=0;i<4;++i) {
        for(int k=1;k<=2;++k) {
            switch(op[i]) {
                case '*': res = a[k-1]*a[k]; break;
                case '/': res = (float)a[k-1]/a[k];break;
                case '+': res = a[k-1]+a[k]; break;
                case '-': res = a[k-1]-a[k]; break;
            }
            if(res == a[(k+1)%3]) {
                printf("%d%c%d%c%d",a[0],(k+1)%3?op[i]:'=',a[1],(k+1)%3?'=':op[i],a[2]);
                return 0;
            }
        }
    }
}