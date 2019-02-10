#include <iostream>
using namespace std;
inline int Max(int&a,int&b) {return a>=b?a:b;}
int main() {
    int times;
    int **c = new int*[2], **sel_sum = new int*[2], *no_sel_sum;
    cin >> times;
    while(times) {
        int n;
        cin >> n;
        for(int i=0;i<2;++i) {
            sel_sum[i] = new int[n];
            c[i] = new int[n];
        }
        no_sel_sum = new int[n];
        for(int j=0;j<n;++j)
            cin >> c[0][j];
        for(int j=0;j<n;++j)
            cin >> c[1][j];
        int k = 0, h = 1;

        sel_sum[0][0] = c[0][0];
        sel_sum[1][0] = c[1][0];
        no_sel_sum[0] = 0;

        bool sel  = true;
        for(int j=1;j<n;j++) {
            no_sel_sum[j] = Max(sel_sum[1][j-1],sel_sum[0][j-1]);
            sel_sum[k][j] = c[k][j] + Max(sel_sum[h][j-1],no_sel_sum[j-1]);
            sel_sum[h][j] = c[h][j] + Max(sel_sum[k][j-1],no_sel_sum[j-1]);
            if(sel) { k++; h--; }
            else { k--; h++; }
            sel = !sel;
        }
        cout << Max(sel_sum[0][n-1],sel_sum[1][n-1]) << endl;
        for(int i=0;i<2;++i) { delete[] sel_sum[i],delete[] c[i]; } delete[] no_sel_sum;
        times--;
    }
    return 0;
}