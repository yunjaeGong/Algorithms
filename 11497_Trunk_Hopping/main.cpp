#include <iostream>
#include <algorithm>

using namespace std;
bool comp(int &a, int &b) { return a>b; }
int main() {
    int T;
    cin >> T;
    while(T) {
        int n, Max;
        cin >> n;
        int *a = new int[n];
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        int i = 1;
        sort(a,a+n,comp);
        Max = max(a[0]-a[1], a[0]-a[2]);
        while(i+2<n) {
            if(i+3<n)
                if(a[i+1]-a[i+3]>Max)
                    Max = a[i+1]-a[i+3];
            if(a[i]-a[i+2]>Max)
                Max = a[i]-a[i+2];
            i+=2;
        }
        Max = max(Max, a[n-2]-a[n-1]);
        cout << Max << endl;
        T--;
        delete[] a;
    }
    return 0;
}