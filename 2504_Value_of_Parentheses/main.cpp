#include <bits/stdc++.h>
#define Pair pair<char,int>
using namespace std;
int main() {
    int sum = 0;
    string s;
    stack<char> st;
    list<Pair> seq;
    cin >> s;
    for(int i=0;i<s.size();++i) {
        if(s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else { // 닫는 괄호
            char p = st.top()=='('?2:3;
            st.pop();
            seq.emplace_back(make_pair(p,st.size()));
        }
    }
    int n = seq.size();
    auto it = seq.begin();
    while(!seq.empty() && it!=seq.end()) {
        if (it->second == 0) {
            it = seq.erase(it);
            it++;
            continue;
        }
        int tmp = it->first;
        // auto itk = it;
        for (auto it2 = it; it2 != seq.end();) {
            ++it2;
            if (it->second - it2->second == 1) {
                tmp *= it2->first;
                it2 = seq.erase(it2);
            }
            if (it2->second == 0) {
                break;
            }
        }
        sum += tmp;
        cout << tmp << endl;
        it++;
    }
    cout << sum;
}