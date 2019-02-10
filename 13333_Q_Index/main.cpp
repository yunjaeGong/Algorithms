#include <iostream>
#include <algorithm>

using namespace std;
int Bin_Search_GE(int array[], int begin, int end, const int target, int size) {
    // 같거나 큰 값의 인덱스를 반환하는 이진탐색
    if(begin == end)
        return array[begin] >= target? begin:-1; //작거나 같은수면 index, 만족하지 않으면 -1 반환
    int mid = (begin + end)/2;
    if(array[mid]<target)
        return Bin_Search_GE(array,mid+1,end,target,size);
    int ret = Bin_Search_GE(array,begin,mid,target,size);
    return ret == -1? mid:ret;
}

int main() {
    int n,index;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;++i)
        cin >> arr[i];
    sort(arr,arr+n); // 정렬시 "나머지 n − k 편의 논문들 인용회수가 각각 k 번 이하라면, 해당 학생의 q-인덱스는 k이다." 조건을 확인하기 쉬움.
    // (3 4 5 8 10)과 같은 상태일때, k가 4라면, 4보다 같거나 큰 수는 4개 이상임을 쉽게 알 수 있음.

    for(int i=n;i>=0;--i) {
        index = Bin_Search_GE(arr,0,n-1,i,n); // i를 이진탐색을 이용해 arr에서 찾는다. (같거나 큰 값의 index 반환)
        if(i <= n - index && index != -1) { // q인덱스 조건을 만족하면 출력하고 종료한다.
            cout << i;
            return 0;
        }
    }
}