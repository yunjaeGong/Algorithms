#include <iostream>

using namespace std;
int arr[51], loss[51], cnt, N, K;;
void swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}

void fac(int i, int j) { // nPn의 경우
    // nPm이라면?
    // i 는 m개 중 i개 수가 선택됐음을 뜻함
    if(i == j) { // m
        cnt++;
        return;
    }
    for(int k=i;k<=j;++k) { // n
        swap(arr[k], arr[i]);
        if(loss[i-1] + arr[i] - K >= 500) {
            loss[i] = loss[i-1] + arr[i] - K;
            fac(i+1, j);
        }
        swap(arr[k], arr[i]);
    }
}

int main() {
    cin >> N >> K;
    for(int i=1;i<=N;++i)
        cin >> arr[i];
    loss[0] = 500;
    fac(1, N);
    cout << cnt;
}
