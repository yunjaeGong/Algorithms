#include <iostream>
#define ull unsigned long long
int jump[100][100];
ull ways[100][100];
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin >> jump[i][j];
    ways[0][0] = 1;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j) {
            int a = i+jump[i][j], b = j+jump[i][j];
            if(i==n-1 && j == n-1)
                continue;
            if(a<100)
                ways[a][j] += ways[i][j];
            if(b<100)
                ways[i][b] += ways[i][j];
        }
    cout << ways[n-1][n-1];
}
