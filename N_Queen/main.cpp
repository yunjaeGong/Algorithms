#include <iostream>
using namespace std;
int n;
bool Place(int i, int column, int x[]) { // (i, column) 위치에 Queen을 놓을 때 가능한지
    //같은 행에 있는 경우는 고려할 필요 없음(같은 행에는 하나만 놓았기 때문) -> 대각, 같은 열만 확인
    for(int r=1;r<=i-1;++r)
        if(x[r] == column || (abs(x[r]-column)/float(i-r))==1.0) // 같은 열 || 대각선인 경우 확인(기울기가 1인가?)
            return false;
    return true;
}
bool N_Queen(int i, int x[]) {
    for(int column=1;column<=n;++column) { // i-1까지의 해는 이미 x[]에 존재 xi 위치에 놓을 수 있는지 없는지 판별
        if(Place(i, column, x)) {// 답이 될 가능성이 있는지
            x[i] = column;
            if(i == n) return true; // n, column 위치에 놓을 수 있으면 true 반환
            if(N_Queen(i+1, x)) return true;//i+1에 놓을 수 있으면 반환
            // 닶이 없으면 다음 column으로
        }
        // i, column에 놓을 수 없으면 다음 column 탐색
    }
    return false; // i 행 모두 탐색했지만 놓을 수 없으면 false 반환 -> 다음 column으로
}
int count = 0;
bool N_Queen_count(int i, int x[]) {
    for(int column=1;column<=n;++column) { // i-1까지의 해는 이미 x[]에 존재 xi 위치에 놓을 수 있는지 없는지 판별
        if(Place(i, column, x)) {// 답이 될 가능성이 있는지
            x[i] = column;
            if(i == n) {
                ++count;
                return true; // n, column 위치에 놓을 수 있으면 true 반환
            }
            N_Queen_count(i+1, x);
            // 답이 없으면 다음 column으로
        }
        // i, column에 놓을 수 없으면 다음 column 탐색
    }
    return false; // i 행 모두 탐색했지만 놓을 수 없으면 false 반환 -> 다음 column으로
}
int main() {
    cin >> n;
    int x[n+1];
    if(N_Queen(1,x)) {
        for(int i=1;i<=n;++i)
            cout << x[i] << " ";
    }
    else cout << "do not exist";

    cout << endl;
    N_Queen_count(1,x); // 생성 가능한 가짓수
    cout << count;

}