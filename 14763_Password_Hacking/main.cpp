#include <algorithm>
#include <cstdio>
int main() {
    int N;
    scanf("%d",&N);
    char s[20];
    double p[N],nP=0, r=1;
    for(int i=0;i<N;++i)
        scanf("%s%lf",s,&p[i]);
    std::sort(p,p+N);
    for(int i=N-1;i>=0;--i) {
        nP += p[i];
        r += (1-nP);
    }
    printf("%.4lf",r);
}

/* https://www.acmicpc.net/problem/14763
 * optimal order -> try out with the highest P
 * expected number of attempts -> like Binomial Distribution. attempts to hack the password.
 * i.e sum of 1(first attempt), 1-p1, 1-p1-p2, ...
 */