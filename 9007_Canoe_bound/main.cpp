#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    int times, k, n;
    vector<int> result;
    cin >> times;
    while (times) {
        // k, n 입력
        cin >> k >> n;
        vector<int> class_2(n*n), class_4(n*n);
        int *class_1 = new int[n], *class_3 = new int[n]; // 1번과 3번 학급만 배열에 입력
        //n개의 리스트 입력받기

        // 첫 학급 입력
        for (int i = 0; i < n; ++i) {
            cin >> class_1[i];
        }
        // 둘째 학급 입력(1,2학급 더해서 저장)
        for (int i = 0, k=0, in; i < n; i++){
            cin >> in;
            for (int j = 0; j < n; j++){
                class_2[k] = in + class_1[j];
                k++;
            }
        }
        // 셋째 학급 입력
        for (int i = 0; i < n; ++i) {
            cin >> class_3[i];
        }
        // 넷째 학급 입력
        for (int i = 0, k=0, in; i < n; i++){
            cin >> in;
            for (int j = 0; j < n; j++){
                class_4[k] = in + class_3[j];
                k++;
            }
        }

        // 오름차순 정렬
        sort(class_2.begin(), class_2.end());
        sort(class_4.begin(), class_4.end());

        // 비교에 사용할 두 변수 선언(초기화 INT_MAX)
        int difference = INT32_MAX; // 최적값과의 편차를 저장할 변수
        int candidate = INT32_MAX; // 최적값에 가장 가까운 후보

        // 비교 시작
        for (int i = 0; i < n * n; ++i) { // 둘째 학급의 모든 원소에 대해
            int target = k - class_2[i]; // 둘째 학급의 모든 원소에 대해, 최적값 = 학급2의 원소 + 학급4의 원소
            auto it = upper_bound(class_4.begin(),class_4.end(),target); // target보다 큰 값의 이터레이터
            /*// 현재 편차가 이전 편차보다 작을 때
                if (difference > abs(k - (class_2[i] + *it))) { // 오른쪽 후보의 편차가 이전 편차보다 작을 때
                    difference = abs(k - (class_2[i] + *it));
                    candidate = class_2[i] + *it; // 왼쪽 편차와 오른쪽 편자 중 작은 값을 택함 (같으면 왼쪽 편차의 값 저장) ex) k = 200이고, 198, 202이면 198 저장
                }*/
            it = lower_bound(class_4.begin(),class_4.end(),target); //왼쪽 후보의 인덱스 찾기
            it = *it==target?it:it-1;
            if (difference >= abs(k - (class_2[i] + *it))) {
                difference = abs(k - (class_2[i] + *it));
                candidate = min(candidate, class_2[i] + *it);
            } // end of if
            if (k == candidate) { // 네 선수의 합이 최적의 선수 무게의 합(k)와 같으면 break
                candidate = k;
                difference = 0;
                break;
            }
        } //비교 끝
        cout << candidate << endl;
        delete[] class_1, delete[]class_3;
        class_2.clear(), class_4.clear();
        times--;
    } // end of while
} // end of main