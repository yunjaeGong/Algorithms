#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
void comb(vector<int> &v,int arr[], int i, int m) { // nC6
    if(i<=6 && m<=N) {
        arr[i-1] = v[m-1];
        if(i == 6) { // base case
            int tmp[7];
            memcpy(tmp, arr,sizeof(int)*6);
            for(int i=0;i<6;++i)
                printf("%d ",arr[i]);
            printf("\n");
            comb(v,arr,i,m+1);
            return;
        }
        comb(v,arr, i+1, m+1); // i+1번째 값으로 m+1 선택하는 경우
        comb(v,arr, i, m+1);// i번째 값으로 m+1 선택하는 경우
    }
}
int main() {
    int in;
    vector<int> v;
    while(scanf("%d",&N) && N!=0){
        for(int i=0;i<N;++i) {
            scanf("%d",&in);
            v.push_back(in);
        }
        int c[7];
        sort(v.begin(),v.end());
        comb(v,c,1,1);
        printf("\n");
        v.clear();
    }
}