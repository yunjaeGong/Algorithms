#include <iostream>
using namespace std;
int main() {
    int A, B, C, D, V;
    cin >> A >> B >> C >> D;
    for(int i=0; i<3; i++){
        cin >> V;
        cout << (V%(A+B)<=A && V%(A+B)>0) + (V%(C+D)<=C && V%(C+D)>0) << endl;
    }
}