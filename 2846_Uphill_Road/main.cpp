#include <cstdio>
using namespace std;
int main() {
    int n;
    int arr[1001];
    int max = 0, diff = 0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for (int i = 1; i < n; i++) {
        (arr[i]-arr[i-1]>0)?diff+=(arr[i]-arr[i-1]) : diff=0;
        if (max < diff)
            max = diff;
    }
    printf("%d",max);
}