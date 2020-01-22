#include <cstdio>
#include <cstring>

using namespace std;
bool S[21];
int main() {
    int M, x;
    char inp[10];
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        scanf("%s", inp);
        if(inp[0] == 'a' && inp[1] == 'd') {
            scanf("%d", &x);
            S[x-1]=true;}
        else if(inp[0] == 'r') {
            scanf("%d", &x);
            S[x-1]=false;}
        else if(inp[0] == 'c') {
            scanf("%d", &x);
            printf("%d\n", S[x-1] ? 1 : 0);}
        else if(inp[0] == 't') {
            scanf("%d", &x);
            S[x-1] = !S[x-1];}
        else if(inp[0] == 'e') memset(S, false, sizeof(S));
        else memset(S, true, sizeof(S));
    }
}