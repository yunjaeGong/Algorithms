#include <iostream>

using namespace std;

int Bin_Search_LE(int array[], int begin, int end, const int target, int size) {
    // 같거나 가장 가까운 인덱스를 반환하는 이진탐색
    if(begin == end)
        return array[begin] <= target? begin:-1; //작거나 같은수면 index, 만족하지 않으면 -1 반환
    int mid = (begin + end)/2;
    if(array[mid]>target)
        return Bin_Search_LE(array,begin,mid,target,size);
    int ret = Bin_Search_LE(array,mid+1,end,target,size);
    return ret == -1? mid:ret;
}
int Bin_Search_GE(int array[], int begin, int end, const int target, int size) {
    // 같거나 가장 가까운 인덱스를 반환하는 이진탐색
    if(begin == end)
        return array[begin] >= target? begin:-1; //작거나 같은수면 index, 만족하지 않으면 -1 반환
    int mid = (begin + end)/2;
    if(array[mid]<target)
        return Bin_Search_GE(array,mid+1,end,target,size);
    int ret = Bin_Search_GE(array,begin,mid,target,size);
    return ret == -1? mid:ret;
}

int main() {
    int begin = 0, end = 9, target = 7, n = 10;
    int a[n] = {1,2,3,4,5,6,8,9,10,11};

    int result_LE = Bin_Search_LE(a,begin,end,target,n);
    int result_GE = Bin_Search_GE(a,begin,end,target,n);
    cout << a[result_LE] << endl;
    cout << a[result_GE];
    return 0;
}

