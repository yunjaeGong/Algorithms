#include <cstdio>
int A, B, C, D, P;
/*
 * A: X 사의 리터당 요금
 * B: Y 사의 기본요금
 * C: Y 사의 기본요금 상한(L)
 * D: Y 사의 리터당 추가요금 (B + D 원)
 * P: JOI 군의 총 사용량
 */
int X_com() { return A*P; } // X 회사
int Y_com() { return P>C?(B + (P-C)*D):B; } // Y 회사 요금
int main() {
    scanf("%d%d%d%d%d",&A,&B,&C,&D,&P);
    int X = X_com(), Y = Y_com();
    printf("%d",X<Y?X:Y);
}