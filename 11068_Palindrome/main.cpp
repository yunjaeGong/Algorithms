#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T, num;
    cin >> T;
    while(T) {
        int i,j;
        cin >> num;
        for(i=2;i<=64;++i) {
            int tmp = num;
            vector<int> V;
            while(tmp) {
                V.push_back(tmp%i);
                tmp /= i;
            }
            for (j = 0; j < V.size(); j++) if (V[j] ^ V[V.size() - 1 - j]) break;
            if (j == V.size()) break;
    }
        cout << (int)(i<=64) << endl;
        T--;
    }
    return 0;
}