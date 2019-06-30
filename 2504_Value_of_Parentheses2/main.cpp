#include <stdio.h>
#include <stack>
using namespace std;

int main() {
    char s[40];
    int sum = 0, tmp = 1;
    stack<char> st;
    scanf("%s", s+1);
    for (int i = 1; s[i]; i++) {
        switch (s[i]) {
            case '(':
                tmp *= 2, st.push('(');
                break;
            case '[':
                tmp *= 3, st.push('[');
                break;
            case ')':
                if (s[i - 1] == '(')
                    sum += tmp;
                if (st.empty())
                    return !printf("0");
                if (st.top() == '(')
                    st.pop();
                tmp /= 2;
                break;
            case ']':
                if (s[i - 1] == '[')
                    sum += tmp;
                if (st.empty())
                    return !printf("0");
                if (st.top() == '[')
                    st.pop();
                tmp /= 3;
        }
    }
    printf("%d",st.empty()?sum:0);
    return 0;
}