#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int T, k, n;
    cin >> T;
    while (T--) {
        // k, n 입력
        cin >> k >> n;

        int cls[4][1000];
        vector<int> c1, c2;

        // 둘째 학급 입력(1,2학급 더해서 저장)
        for(int i=0;i<4;++i)
            for(int j=0;j<n;++j)
                scanf("%d", &cls[i][j]);

        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j) {
                c1.push_back(cls[0][i] + cls[1][j]);
                c2.push_back(cls[2][i] + cls[3][j]);
            }

        // 오름차순 정렬
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());

        // 비교에 사용할 두 변수 선언(초기화 INT_MAX)
        int diff = INT32_MAX; // 최적값과의 편차를 저장할 변수
        int candidate = INT32_MAX; // 최적값에 가장 가까운 후보

        // 비교 시작

        int left = 0, right = n*n-1;

        while (left < n*n && right >= 0) {
            int sum = c1[left] + c2[right]; //c1은 왼쪽부터, c2는 오른쪽부터 검사
            if (sum > k) { // 합이 k 보다 큰 경우
                if (sum-k < diff) { // 합의 차이가 예전에 구한 것보다 작으면
                    diff = sum - k; // 업데이트하고
                    candidate = sum; // 답으로 저장
                }
                right--; // 합이 줄도록 오른쪽을 내림
            } else if (sum < k) { //합이 보트의 특정 값보다 작은 경우
                if (k-sum <= diff) {
                    diff = k - sum;
                    candidate = sum;
                }
                left++; // 합이 커지도록 왼쪽을 올림
            } else { //sum == k 답을 찾은 경우
                candidate = sum;
                break;
            }
        }
        printf("%d\n", candidate);
        c1.clear(), c2.clear();
    } // end of while
} // end of main