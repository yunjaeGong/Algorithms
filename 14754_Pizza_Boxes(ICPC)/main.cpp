#include <cstdio>
#include <set>
using namespace std;
int main() {
    long long n, m, tmp, r_max = 0, total=0, sum=0;
    set<long long> S;
    scanf("%lld%lld",&n,&m); // row, column
    int c_arr[m];
    for(int i=0;i<m;++i)
        c_arr[i] = 0;
    for(int i=0;i<n;++i) { // row
        r_max = 0;
        for(int j=0;j<m;++j) { // col
            scanf("%lld", &tmp);
            total += tmp;
            if(tmp > c_arr[j])
                c_arr[j] = tmp;
            if(tmp > r_max)
                r_max = tmp;
        }
        S.insert(r_max);
    }
    for(int i=0;i<m;++i)
        S.insert(c_arr[i]);
    for(int e:S)
        sum += e;
    printf("%lld",total-sum);
}