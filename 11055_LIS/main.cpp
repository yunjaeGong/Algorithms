#include <iostream>
using namespace std;
int main() {
    int n, max=0;
    cin >> n;
    int a[n+1], b[n+1];
    for(int i=1, j;i<=n;++i) {
        int tmp_max = 0;
        scanf("%d",&a[i]);
        for(j=1;j<i;++j) {
            if(a[i] > a[j])
                if(b[j] > tmp_max)
                    tmp_max = b[j];
        }
        b[i] = tmp_max + a[j];
        if(b[i]>max) max = b[i];
    }
    cout << max;
}