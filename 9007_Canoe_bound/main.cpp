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

        int cls[4][1000];
        vector<int> c1, c2;

        // 둘째 학급 입력(1,2학급 더해서 저장)
        for(int i=0;i<4;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&cls[i][j]);

        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                c1.push_back(cls[0][i] + cls[1][j]);
                c2.push_back(cls[2][i] + cls[3][j]);
            }
        }

        // 오름차순 정렬
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        // 비교에 사용할 두 변수 선언(초기화 INT_MAX)
        int difference = INT32_MAX; // 최적값과의 편차를 저장할 변수
        int candidate = INT32_MAX; // 최적값에 가장 가까운 후보

        // 비교 시작
        for (int i = 0; i < n * n; ++i) { // 둘째 학급의 모든 원소에 대해
            int target = abs(k - c2[i]); // 둘째 학급의 모든 원소에 대해, 최적값 = 학급2의 원소 + 학급4의 원소
            // if(target <= 0) continue;
            // vector<int>::iterator u_it = upper_bound(c1.begin(),c1.end(),target); // target보다 큰 값의 이터레이터
            int idx = lower_bound(c1.begin(),c1.end(),target) - c1.begin(); //왼쪽 후보의 인덱스 찾기
            // 왼쪽 편차와 오른쪽 편자 중 작은 값을 택함 (같으면 왼쪽 편차의 값 저장) ex) k = 200이고, 198, 202이면 198 저장
            int l_idx = idx > 0?idx-1:0;
            if (difference >= abs(k - (c2[i] + c1[idx]))) {
                difference = abs(k - (c2[i] + c1[idx]));
                candidate = min(candidate, c2[i] + c1[idx]);
            }
            if(difference >= abs(k - (c2[i] + c1[l_idx]))) {
                difference = abs(k - (c2[i] + c1[l_idx]));
                candidate = min(candidate, c2[i] + c1[l_idx]);
            }
            // end of if
            if (k == candidate) { // 네 선수의 합이 최적의 선수 무게의 합(k)와 같으면 break
                candidate = k;
                difference = 0;
                break;
            }
        } //비교 끝
        cout << candidate << endl;
        c1.clear(), c2.clear();
        times--;
    } // end of while
} // end of main