#include <iostream>
#include <deque>
using namespace std;
int main() {
    int N;
    std::cin >> N;
    deque<int> dQ;
    for(int i=0;i<N;++i)
        dQ.push_back(i+1);
    if(N != 1) dQ.pop_front();
    while(!dQ.empty()) {
        dQ.push_back(dQ.front());
        dQ.pop_front();
        if(dQ.size() == 1) break;
        dQ.pop_front();
    }
    cout << dQ.front();
}
