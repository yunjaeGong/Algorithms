#include <cstdio>
#include <algorithm>
using namespace std;
int arr[9], res[7];
bool first = true;
void Combination (int c[], int i, int n, int sum) {
    if(i<7 && n<9) {
        res[i] = c[n];
        if(i == 6) {
            if(sum == 100 && first) {
                sort(res,res+7);
                for(int i=0;i<7;++i)
                    printf("%d\n",res[i]);
                first = false;
                return;
            }
            if(n+1<9)
                Combination(c,i,n+1,sum - c[n] + c[n+1]);
            return;
        }
        if(n+1<9) {
            Combination(c,i+1,n+1,sum + c[n+1]); // i를 선택하는 경우
            Combination(c,i,n+1,sum - c[n] + c[n+1]); // i를 선택하지 않는 경우
        }
    }
}

int main () {
    for(int i=0;i<9;++i)
        scanf("%d",&arr[i]);
    Combination(arr,0,0,arr[0]);
}