#include <cstdio>
#include <algorithm>
using namespace std;
struct T{int s,e;
bool operator<(const T &a) {if(e!=a.e) return e<a.e; else return s<a.s;}};
int main() {
    int N,s,e,cnt=1;
    scanf("%d",&N);
    T a[N];
    for(int i=0;i<N;++i) {
        scanf("%d%d",&s,&e);
        a[i] = {s,e};
    }
    sort(a,a+N);
    int i=0,j;
    for(;i<N-1;) {
        for(j=i+1;j<N;++j) {
            if(a[i].e <= a[j].s) {
                cnt++;
                break;
            }
        }
        i=j;
    }
    printf("%d",cnt);
}