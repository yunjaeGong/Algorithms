#include <iostream>
int bounty_1[] = {500, 300, 200, 50, 30, 10};
int bounty_2[] = {512, 256, 128, 64, 32};
int sum_1[] = {1, 3, 6, 10, 15, 21}, sum_2[] = {1, 3, 7, 15, 31};
using namespace std;
int main() {
    int T, a, b;
    cin >> T;
    while(T--) {
        int res = 0;
        cin >> a >> b;
        for(int i=0;i<6;++i) {
            if(!a) break;
            if(a <= sum_1[i]) {
                res += bounty_1[i];
                break;
            }
        }
        for(int i=0;i<5;++i) {
            if(!b) break;
            if(b <= sum_2[i]) {
                res += bounty_2[i];
                break;
            }
        }
        cout << res*10000 << '\n';
    }
}