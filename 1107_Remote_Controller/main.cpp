#include <iostream>
#include <string>

using namespace std;
bool brok[10];
int a, M;
string N, S, B;

int main() {
    cin >> N >> M;
    for(int i=0;i<M;++i) {
        cin >> a;
        brok[a] = true;
    }
    int cur = 100,  cnt = 0, len = N.length();
    for(int i=0;i<len;++i) {
        int b = N[i]-'0', s = N[i]-'0';
        while(!brok[b] && b <= 9) {
            b++;
        }
        while(!brok[s] && s >= 0) {
            s--;
        }
        if(brok[s] && brok[b]) {
            S = to_string(100);
            B = to_string(100);
            break;
        }
        if(!brok[s] && !brok[b]) {
            S.push_back(s);
            B.push_back(b);
            continue;
        }
        if(!brok[s])
            s = b;
        if(!brok[b])
            b = s;
        S.push_back(s);
        B.push_back(b);
    }
    int s = stoi(S), b = stoi(B), cnt_s=0, cnt_b=0;
    while(s != stoi(N)) {
        s++;
        cnt_s++;
    }
    while(b != stoi(N)) {
        b--;
        cnt_b++;
    }
    cout << min(cnt_s, cnt_b);
}
