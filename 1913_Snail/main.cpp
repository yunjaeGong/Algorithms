#include <iostream>
int main() {
    int N, C;
    scanf("%d%d",&N,&C);
    int *A[N];
    for(int i=0;i<N;++i)
        A[i] = new int[N];
    int i=-1,j=0,k,l=N,n,sub=1,num = N*N;
    int x, y;
    while(1){
        for(k=0;k<l;k++){ // 행에 숫자 삽입
            i += sub;
            A[i][j] = num;
            if(num == C) { x = j, y = i; }
            num--;
        }
        l--; // 행,열의 개수 감소
        if(l<0) break;
        for(k=0;k<l;k++){ // 열에 숫자 삽입
            j += sub;
            A[i][j] = num;
            if(num == C) { x = j, y = i; }
            num--;
        }
        sub = -sub; // 방향 전환
    }
    for(k=0;k<N;k++){
        for(n=0;n<N;n++){
            printf("%d ",A[k][n]);
        }
        printf("\n");
    }
    printf("%d %d",y+1,x+1);
}
