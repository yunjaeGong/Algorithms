#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct tup {
    int n;
    string name;
};
bool comp (const tup &a, const tup &b) {
    return a.n<b.n;
}
int main() {
    int N;
    cin >> N;
    vector<tup> v(N);
    for(int i=0;i<N;++i) {
        int n;
        string a;
        cin >> n >> a;
        v[i] = {n,a};
    }
    stable_sort(v.begin(),v.end(),comp);
    for(int i=0;i<N;++i)
        cout << v[i].n << " " << v[i].name << '\n';
}