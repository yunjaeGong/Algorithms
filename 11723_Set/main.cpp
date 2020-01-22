#include <cstdio>
using namespace std;
int main() {
    int M, mask = 0, x;
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        char inp[10];
        scanf("%s", inp);
        if(inp[0] == 'a' && inp[1] == 'd') {
            scanf("%d", &x);
            mask |= 1 << --x;}
        else if(inp[0] == 'r') {
            scanf("%d", &x);
            mask &= ~(1 << --x);}
        else if(inp[0] == 'c') {
            scanf("%d", &x);
            printf("%d\n", (mask & 1 << --x) ? 1 : 0);}
        else if(inp[0] == 't') {
            scanf("%d", &x);
            if(mask & 1 << --x) mask &= ~(1 << x);
            else mask |= 1 << x;}
        else if(inp[0] == 'e') mask = 0;
        else mask = (1 << 20) - 1;
    }
}