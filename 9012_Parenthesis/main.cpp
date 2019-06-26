#include <iostream>
#include <stack>
#include <string>
#define unll unsigned long long
#define ll long long
#define INF 1<<31-1
#define mmax(x,y) ((x)<(y)?(x):(y))
#define mmin(x,y) ((x)<(y)?(y):(x))
#define pb push_back
#define ffor(i,a,n) for(ll i = (ll)a; i<(ll)n; i++)
#define iscanf(k) scanf("%d", &k)
#define fscanf(k) scanf("%f", &k)
#define llscanf(k) scanf("%ll", &k)
using namespace std;
int main() {
    int N, if_b = 0;
    string str;
    iscanf(N);
    ffor(i,0,N) {
        stack<char> s;
        if_b = 0;
        str.clear();
        cin >> str;
        ffor(j,0,str.size()) {
            if(str[j] == ')') {
                if(s.empty() || s.top() == ')') {
                    if_b=1;
                    break;
                }
                if(s.top() == '(')
                    s.pop();
            }
            else
                s.push(str[j]);
        }
        if(!s.empty() || if_b==1) cout << "NO" << endl;
        else if(s.empty()) cout << "YES" << endl;
    }
}