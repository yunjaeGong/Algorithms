#include <iostream>

int tmp;
void swap(int &a, int &b) { tmp = a; a = b; b = tmp; }

void makeHeap(int *arr, int n, int i) { // Max heap
    int L = 2*i+1, R = 2*i+2;
    int biggest = i;
    if(L < n && arr[L] > arr[biggest])
        biggest = L;
    if(R < n && arr[R] > arr[biggest])
        biggest = R;
    if(biggest != i) { // 가장 큰 값이 루트이면 바꿀 필요 없음!
        swap(arr[biggest], arr[i]);
        makeHeap(arr, n, biggest);
    }
}

void heapSort(int *arr, int n) {
    for(int i=n/2;i>=0;--i)
        makeHeap(arr, n, i);

    for(int i=n-1;i>=0;--i) {
        swap(arr[0], arr[i]);
        makeHeap(arr, i, 0);
    }
}

int main() {
    
}