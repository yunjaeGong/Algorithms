#include <iostream>
using namespace std;
inline int Max(int&a,int&b) {return a>=b?a:b;}
int main() {
    int times;
    int **c = new int*[2], **sel_sum = new int*[2], **no_sel_sum = new int*[2];
    cin >> times;
    while(times) {
        int n;
        cin >> n;
        for(int i=0;i<2;++i) {
            sel_sum[i] = new int[n];
            no_sel_sum[i] = new int[n];
            c[i] = new int[n];
        }
        for(int j=0;j<n;++j)
            cin >> c[0][j];
        for(int j=0;j<n;++j)
            cin >> c[1][j];
        int k = 0, h = 1;
        no_sel_sum[0][0] = 0;
        no_sel_sum[1][0] = 0;
        sel_sum[0][0] = c[0][0];
        sel_sum[1][0] = c[1][0];
        bool sel  = true;
        for(int j=1;j<n;j++) {
            int a = no_sel_sum[0][j-1], b = no_sel_sum[1][j-1];
            int max_no_sel = Max(a,b);
            no_sel_sum[0][j] = Max(a,sel_sum[0][j-1]);
            no_sel_sum[1][j] = Max(b,sel_sum[1][j-1]);
            sel_sum[k][j] = c[k][j] + Max(sel_sum[h][j-1],max_no_sel);
            sel_sum[h][j] = c[h][j] + Max(sel_sum[k][j-1],max_no_sel);
            if(sel) { k++; h--; }
            else { k--; h++; }
            sel = !sel;
        }
        cout << Max(sel_sum[0][n-1],sel_sum[1][n-1]) << endl;
        for(int i=0;i<2;++i) { delete[] sel_sum[i],delete[] no_sel_sum[i],delete[] c[i]; }
        times--;
    }
    return 0;
}