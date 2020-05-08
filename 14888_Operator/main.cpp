#include <iostream>
using namespace std;
int N, MIN = 1<<30, MAX=-1*1<<30;
int arr[11], op[4], res[11];

void calc(int a, int s, int m, int  d, int dep, int sum) {
    if(dep==N) {
        MIN = min(MIN, sum);
        MAX = max(MAX, sum);
        return ;
    }
    if(a > 0)
        calc(a-1, s, m, d, dep+1, sum + arr[dep]);
    if(s > 0)
        calc(a, s-1, m, d, dep+1, sum - arr[dep]);
    if(m > 0)
        calc(a, s, m-1, d, dep+1, sum * arr[dep]);
    if(d > 0)
        calc(a, s, m, d-1 , dep+1, sum / arr[dep]);
}
int main() {
    int a, s, m, d;
    cin >> N;
    for(int i=0;i<N;++i)
        cin >> arr[i];
    cin >> a >> s >> m >> d;
    calc(a,s,m,d,1,arr[0]);
    cout << MAX << '\n' << MIN;
}
