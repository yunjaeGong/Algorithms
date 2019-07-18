#include <cstdio>
#define ull unsigned long long
inline ull max(ull a, ull b) {return a>b?a:b;}
int main() {
    int n;
    unsigned long long arr[501]={0,},in=0, Max=0, prev=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        for(int j=i-1;j>=0;--j) {
            scanf("%lld",&in);
            if(j == 0)
                arr[0] += in;
            else if(j == i-1)
                arr[j] = (prev+in);
            else {
                arr[j] = (max(arr[j],arr[j-1]) + in);
            }
            if(arr[j] > Max) Max = arr[j];
            prev = arr[i-1];
        }
    }
    printf("%lld",Max);
}