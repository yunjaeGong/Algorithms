#include <iostream>
#define DIV 1000000000
int main() {
    int n, op=1, a = 0, b = 1, c=1, res=0;
    std::cin >> n;
    if (n<0){
        if(n%2== 0)
            op = -1;
        n*=-1;
    } else if (n == 0)
        op = 0;
    for(int i=0;i<n;++i) {
        if (i == 1)
            res = 1;
        else {
            c = (a + b)%DIV;
            a = b;
            b = c;
            res = c;
        }
    }
    std::cout << op << '\n' << res;
}