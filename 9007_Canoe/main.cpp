#include <iostream>
#include <vector>
#include <algorithm>

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
    int times, k, n;
    vector<int> result;
    cin >> times;
    vector<int> candidates;
    while (times) {
        // k, n 입력
        cin >> k >> n;
        int *class_1 = new int[n], *class_3 = new int[n]; // 1번과 3번 학급만 배열에 입력
        int *added_class_2 = new int[n * n], *added_class_4 = new int[n * n]; // 1,3학급과 2,4학급의 몸무게를 더한 2,4학급
        /*vector<int> added_class_2, added_class_4;*/
        //n개의 리스트 입력받기

        // 첫 학급 입력
        for (int i = 0; i < n; ++i) {
            cin >> class_1[i];
        }
        // 둘째 학급 입력(1,2학급 더해서 저장)
        for (int i = 0, k=0, num=0; i < n; i++){
            cin >> num;
            for (int j = 0; j < n; j++){
                added_class_2[i] = num + class_1[j];
                k++;
            }
        }
        /*for (int i = 0, k=0, num=0; i < n; i++){
            cin >> num;
            for (int j = 0; j < n; j++){
                added_class_2.push_back(num + class_1[j]);
            }
        }*/

        // 셋째 학급 입력
        for (int i = 0; i < n; ++i) {
            cin >> class_3[i];
        }
        // 넷째 학급 입력
        for (int i = 0, k=0, num=0; i < n; i++){
            cin >> num;
            for (int j = 0; j < n; j++){
                added_class_4[k] = num + class_3[j];
                k++;
            }
        }
        /*for (int i = 0, k=0, num=0; i < n; i++){
            cin >> num;
            for (int j = 0; j < n; j++){
                added_class_4.push_back(num + class_3[j]);
            }
        }*/
        // 입력 끝

        // 오름차순 정렬
        sort(added_class_2, added_class_2 + n * n);
        sort(added_class_4, added_class_4 + n * n);
        /*sort(added_class_2.begin(), added_class_2.end());
        sort(added_class_4.begin(), added_class_4.end());*/
        // 비교에 사용할 두 변수 선언(초기화 INT_MAX)
        int difference = INT32_MAX;
        int candidate = INT32_MAX;

        // 비교 시작
        for (int i = 0; i < n * n; ++i) { // 둘째 학급의 모든 원소에 대해
            int target = k - added_class_2[i];
            int closest_index = Bin_Search_GE(added_class_4, 0, n*n-1, target, n*n); // 작거나 같은 인덱스
            if(closest_index == -1) closest_index = n*n-1;
            // 현재 편차가 이전 편차보다 작을 때

            if (closest_index < n*n) { // 범위 내이고
                if (difference > abs(k - (added_class_2[i] + added_class_4[closest_index]))) { // 오른쪽 후보의 편차가 이전 편차보다 작을 때
                    difference = abs(k - (added_class_2[i] + added_class_4[closest_index]));
                    candidate = added_class_2[i] + added_class_4[closest_index]; // 왼쪽 편차와 오른쪽 편자 중 작은 값을 택함 (같으면 왼쪽 편차의 값 저장) ex) k = 200이고, 198, 202이면 198 저장
                }
            } // end of if
            candidates.push_back(candidate);
            closest_index = Bin_Search_LE(added_class_4, 0, n*n-1, target, n*n); //왼쪽 후보의 인덱스 찾기
            if(closest_index == -1) closest_index = 0;
            if (difference >= abs(k - (added_class_2[i] + added_class_4[closest_index]))) {
                difference = abs(k - (added_class_2[i] + added_class_4[closest_index]));
                candidate = min(candidate, added_class_2[i] + added_class_4[closest_index]);
            } // end of if

            candidates.push_back(candidate);
            if (k == candidate) { // 네 선수의 합이 최적의 선수 무게의 합(k)와 같으면 break
                candidate = k;
                difference = 0;
                break;
            }
        } //비교 끝
        result.push_back(candidate);
        delete[] added_class_2, added_class_4;
        times--;
    } // end of while
    /*for (vector<int>::iterator it = result.begin() ; it != result.end(); ++it)
        cout << *it << endl;*/
    for(int i=0;i<result.size()-1;++i)
        cout << result[i] << endl;
    cout << result.back();
    cout << endl; //로그 출력용
    for(vector<int>::iterator it = candidates.begin(); it != candidates.end(); ++it)
        cout << *it << " ";
} // end of main


