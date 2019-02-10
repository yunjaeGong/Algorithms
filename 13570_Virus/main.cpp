#include <iostream>
using namespace std;
int inf(int *left, int*right, int i) {
    if(left[i] == -1 || right[i] == -1)
        return 1;
    return min(inf(left, right, left[i]), inf(left, right, right[i]))+1;
}
int main() {
    int n;
    cin >> n;
    int* l = new int[n];
    int* r = new int[n];
    for(int i=0;i<n;++i)
        cin >> l[i] >> r[i];
    cout << inf(l,r,0);
    return 0;
}