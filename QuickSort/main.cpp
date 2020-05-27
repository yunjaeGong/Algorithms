#include <iostream>
const int MAX = 10000000;

int tmp;
void swap(int*a, int*b) { tmp = *a; *a = *b; *b = tmp; }

int partition(int *arr, int first, int last) {
    int pivot_idx = rand()%(last-first+1)+first;
    int pivot = arr[pivot_idx], i = first, j = last;
    while(i < j) {
        while(pivot < arr[j])
            j--;
        while(i < j && pivot >= arr[i])
            i++;
        swap(&arr[i], &arr[j]);
    }
    arr[pivot_idx] = arr[i];
    arr[i] = pivot;
    return i;
}

void quickSort(int *arr, int first, int last) {
    if(first >= last)
        return;
    int pivot = partition(arr, first, last);
    quickSort(arr, first, pivot -1);
    quickSort(arr, pivot+1, last);
}

int main() {
}
