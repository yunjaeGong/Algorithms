#include <iostream>
#include <bits/stdc++.h>
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
    bool laser_set = false;
    int cnt = 0;
    string str;
    cin >> str;
    stack<int> s;
    ffor(i,0,str.size()) {
        if(str[i] == ')') {
            s.pop();
            if(laser_set) {
                cnt++;
                continue;
            }
            if(!s.empty()&&s.top() == '(') {
                laser_set = true;
                cnt += s.size();
            }
        }
        else {
            s.push(str[i]);
            laser_set = false;
        }
    }
    cout << cnt;
}