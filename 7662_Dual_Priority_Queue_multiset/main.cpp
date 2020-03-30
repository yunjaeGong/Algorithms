#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int T, N, num;
    char inp[2];
    cin >> T;
    while(T--) {
        cin >> N;
        multiset<int> S;
        for(int i=0;i<N;++i) {
            cin >> inp >> num;
            switch(inp[0]) {
                case 'I': S.insert(num); break;
                case 'D':
                    if(!S.empty()) {
                        if(num == -1) { // 최솟값
                            S.erase(S.begin());
                        } else {
                            auto it = S.end();
                            S.erase(--it);
                        }
                    }
                    break;
            }
        }
        if(S.empty())
            cout << "EMPTY\n";
        else
            cout << *(--S.end()) << " " << *S.begin() << '\n';
    }
}
