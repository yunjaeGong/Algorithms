#include <iostream>
#include "cstring"
using namespace std;

// 양의 정수 n에 대하여, n을 1부터 n까지 숫자들의 합으로 나타내는 방법의 수를 구하시오.
// 단 나열되는 숫자들의 순서는 고려하지 않는다. 1+2와 2+1은 동일한 것으로 간주한다

int main() {
    int n;

    cin >> n;
    int C[n+1][n+1];
    memset(C, 0, sizeof(int)*(n+1)*(n+1));
    // i를 j까지 숫지달의 합으로 나타내는 방법의 수 => Sij라 할 때
    // Sij = Si-cj,j Si,j-1 j를 사용 할 때, 안할때

    for (int i=0;i<=n;++i) {
        for (int j=0;j<=n;++j) {
            if (i == 0)
                C[i][j] = 1;
            else if (j == 0)
                C[i][j] = 0;
            else if (i < j)
                C[i][j] = C[i][i];
            else // i>=j
                C[i][j] = C[i-j][j] + C[i][j-1]; // 각각 j를 사용했을 때 방법의 수, j를 사용하지 않았을 때 방법의 수
        }
    }

    cout << C[n][n];

}
