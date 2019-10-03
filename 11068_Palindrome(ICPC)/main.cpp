#include <cstdio>
#include <deque>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N,B;
        scanf("%d",&N);
        for(B=2;B<=64;++B) {
            deque<int> Q;
            int tmp = N;
            while(tmp) {
                Q.push_front(tmp%B);
                tmp/=B;
            }
            while(!Q.empty()) {
                if(Q.front() != Q.back())
                    break;
                Q.pop_back(); if(!Q.empty())Q.pop_front();
            }
            if(Q.empty()) {
                printf("1\n");
                break;
            }
        }
        if(B > 64)
            printf("0\n");
    }
}