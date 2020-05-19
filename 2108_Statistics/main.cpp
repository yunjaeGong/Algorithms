#include <iostream>
#include <cmath>
using namespace std;
int N, a;
int freq[8001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    cin >> a;
    int min=a, max=a, max_f=1, cnt=0, tgt=N/2+1, median, mode;
    median = a;
    double sum = a;
    freq[a+4000]++;
    for(int i=1;i<N;++i) {
        cin >> a;
        sum += a;
        freq[a+4000]++;
        min = std::min(min, a);
        max = std::max(max, a);
        max_f = std::max(max_f, freq[a+4000]);
    }
    bool isSecond = false;
    for(int i=min+4000;i<=max+4000;++i)
        if(freq[i] == max_f) {
            mode = i-4000;
            if(isSecond)
                break;
            isSecond = true;
        }
    for(int i=min+4000;i<=max+4000;++i) {
        while(freq[i]) {
            freq[i]--;
            cnt++;
            if(cnt == tgt) {
                median = i-4000;
            }
        }
    }
    cout << ((int)floor((sum/N) + 0.5)) << '\n' << median << '\n' << mode << '\n'<< (max-min);
}
