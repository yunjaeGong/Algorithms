#include <cstdio>
int main() {
    int X, sum=0,cnt=0,left=64;
    scanf("%d",&X);
    int left_len = X;
    while(sum != X) {
        if(left <= left_len) {
            cnt ++;
            sum += left;
            left_len-=left;
        }
        left /= 2;
    }
    printf("%d",cnt);
}