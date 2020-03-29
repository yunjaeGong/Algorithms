#include <iostream>
#include <stack>
using namespace std;
int main() {
    string s, res;
    cin >> s;
    stack<char> S;
    for(char c:s) {
        if('A'<=c && c<='Z')
            res.push_back(c);
        else
        switch(c) {
            case '(': S.push(c); break;
            case '*':
            case '/':
                while(!S.empty() && (S.top() == '*' || S.top() == '/')) {
                    res.push_back(S.top());
                    S.pop();
                }
                S.push(c); break;
            case '+':
            case '-':
            case ')':
                while(!S.empty() && S.top() != '(') {
                    res.push_back(S.top());
                    S.pop();
                }
                if(c!=')') S.push(c);
                else S.pop();
                break;
        }
    }
    while(!S.empty()) {
        res.push_back(S.top());
        S.pop();
    }
    cout << res;
}
