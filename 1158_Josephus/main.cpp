#include <iostream>
#include <list>
using namespace std;
int main() {
    int N,K,n=0,k=0;
    int b[5001];
    scanf("%d%d",&N,&K);
    list<int> a;
    for(int i=0;i<N;++i)
        a.push_back(i+1);
    while(!a.empty()) {
        auto it = a.begin();
        n = (n = (n+=K)%a.size())>0?n-1:a.size()-1;
        advance(it,n);
        b[k] = *it;
        k++;
        a.erase(it);
    }
    printf("<");
    for(int i=0;i<N;++i) {
        printf("%d",b[i]);
        if(i!=N-1) printf(", ");
    }


    printf(">");
}