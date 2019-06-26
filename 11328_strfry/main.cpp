#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main() {
    int N;
    scanf("%d",&N);
    while(N) {
        char a[1001], b[1001];
        scanf("%s%s", a,b);
        int n=strlen(a),j=0;
            sort(a, a + n);
            sort(b, b + n);
            for (;j<n;++j)
                if (a[j] != b[j])
                    break;
            if(j==n)
                printf("Possible\n");
            else
                printf("Impossible\n");
        N--;
    }
}