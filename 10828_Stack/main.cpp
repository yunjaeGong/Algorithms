#include <iostream>
#include <string.h>
#define MAX 10000
using namespace std;
int pos = -1;
int *s;
bool empty() { return pos < 0; }
int top() { return empty()?-1:s[pos]; }
int pop() { return empty()?-1:s[pos--]; }
int size() { return pos+1; }
void push(int x) { s[++pos] = x; }

int main() {
    int N, x;
    char a[10];
    s = new int[MAX];
    scanf("%d",&N);
    for(int i=0;i<N;++i) {
        scanf("%s",a);
        switch(strlen(a)) {
            case 3: // pop
                if(strcmp(a,"pop") == 0) {
                    printf("%d\n",empty()?-1:pop());
                    break;
                } else { // top
                    printf("%d\n",empty()?-1:top());
                    break;
                }
            case 4: if(strcmp(a,"push") == 0) {
                    scanf("%d",&x);
                    push(x);
                    break;
                } else if(strcmp(a,"size") == 0) {
                    printf("%d\n",size());
                    break;
                }
            case 5: if(strcmp(a,"empty") == 0)  {
                    printf("%d\n",empty()?1:0);
                    break;
                }break;
        }
    }
    delete[] s;
}
