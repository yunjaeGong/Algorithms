#include <cstdio>
#include <stack>
#include <cstring>
int main() {
    char a[104], B[]={"[]()"};
    char* pch;
    bool T;
    while(1) {
        std::stack<char> Q;
        fgets(a,102,stdin);
        T=true;
        if(a[0] == '.') break;
        pch = strpbrk(a,B);
        while (pch != NULL) {
            if(*pch=='('||*pch=='[')
                Q.push(*pch);
            else if(!Q.empty()&&(*pch==']'||*pch==')')) {
                if(Q.top() == '(' && *pch == ')') Q.pop();
                else if(Q.top() == '[' && *pch == ']') Q.pop();
                else {T=false; break;}
            }
            else if(Q.empty()) {T=false; break;}
            pch = strpbrk (pch+1,B);
        }
        printf("%s\n",T&&Q.empty()?"yes":"no");
    }
}