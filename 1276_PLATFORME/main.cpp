#include <stdio.h>

int N;
struct {int y, x1, x2;} pf[100];

int pillar(double x, int y) {
    int res = 0;
    for (int i=0; i<N; ++i) {
        if (pf[i].y  < y && pf[i].x1 < x && pf[i].x2 > x && pf[i].y  > res)
            res = pf[i].y;
    }
    return y - res;
}

int main() {
    scanf("%d", &N);
    for (int i=0;i<N;++i)
        scanf("%d%d%d", &pf[i].y, &pf[i].x1, &pf[i].x2);
    int res = 0;
    for (int i=0; i<N; ++i) {
        res += pillar(pf[i].x1 + 0.5, pf[i].y);
        res += pillar(pf[i].x2 - 0.5, pf[i].y);
    }
    printf("%d", res);
}