#include <cstdio>
using namespace std;

int tree[10001];

void postorder(int start, int end){
    if(start == end) return;
    if(start+1 == end){
        printf("%d\n", tree[start]);
        return;
    }
    int right = start+1;
    for(;right<end && tree[right]<tree[start];right++);
    postorder(start+1, right);
    postorder(right, end);
    printf("%d\n", tree[start]);
}

int main(){
    int N = 0;
    for(; scanf("%d", tree+N)>0; N++);
    postorder(0, N);
}