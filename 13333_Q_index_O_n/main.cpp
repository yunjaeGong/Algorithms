#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,index;
    cin >> n;
    int *arr = new int[n+1];
    for(int i=0;i<n;++i)
        cin >> arr[i];

    sort(arr,arr+n);

    for (int i = n; i >= 0; i--) if (arr[n - i] >= i) {
        //  k번 이상 인용된 논문이 k편 이상이고 나머지 n − k 편의 논문들 인용회수가 각각 k 번 이하라면, 해당 학생의 q-인덱스는 k이다.
        // i번 이상 인용된 논문이 arr[n-i]편 이상이고, 나머지 n-i편의 논문들 인용회수가 각각 arr[n-i]번 이하라면 해당 학생의 q-인덱스는 i이다.
            cout << i;
            return 0;
        }

}