#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
char inst[100002], list[400005];
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T, N;
    deque<short> dQ;
    cin >> T;
    while(T--) {
        cin >> inst >> N >> list;
        char *ch;
        int len = strlen(inst);
        ch = strtok(list, ",[]");
        if(ch != NULL)
            dQ.push_back(stoi(ch));
        while(ch != NULL) {
            ch = strtok(NULL, ",[]");
            if(ch != NULL)
                dQ.push_back(stoi(ch));
        }
        bool rev = false, if_break=false;
        for(int i=0;i<len;++i) {
            if(inst[i] == 'R') {
                rev = !rev;
                continue;
            }
            if(dQ.empty()) {
                cout << "error\n";
                if_break = true;
                break;
            }
            if(rev)
                dQ.pop_back();
            else
                dQ.pop_front();
        }
        if(if_break)
            continue;
        cout << '[';
        if(!dQ.empty()) {
            if(!rev) {
                cout << dQ.front();
                dQ.pop_front();
                for(auto it=dQ.begin();it!=dQ.end();++it)
                    cout << ',' << *it;
            }
            else {
                cout << dQ.back();
                dQ.pop_back();
                for(auto it=dQ.rbegin();it!=dQ.rend();++it)
                    cout << ',' << *it;
            }
        }
        cout << "]\n";
        dQ.clear();
    }
}

