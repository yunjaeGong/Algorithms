#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    std::cin >> N;
    int arr[11];
    vector<int> v;
    for(int j=1;j<=N;++j)
        cin >> arr[j];
    for(int i=N;i>0;--i)
        v.insert(v.begin()+arr[i], i);
    for(int e:v)
        cout << e << " ";
}
