#include <cstdio>
using namespace std;
int main() {
    int loanDur, nRec;
    double monthlyPay, debt, iRate[101];
    while (true) {
        scanf("%d%lf%lf%d",&loanDur,&monthlyPay,&debt,&nRec);
        if (loanDur < 0)
            break;
        int curMon;
        double interest;
        while (nRec--) {
            scanf("%d%lf",&curMon,&interest);
            for (int i=curMon;i<=100;i++)
                iRate[i] = interest;
        }
        int now = 0;
        double monthlyPayment = debt / loanDur;
        double curVal = (debt + monthlyPay) * (1 - iRate[0]);
        double curLoan = debt;
        while (curVal < curLoan) {
            now++;
            curLoan -= monthlyPayment;
            curVal = curVal * (1-iRate[now]);
        }
        printf("%d month",now);
        if (now != 1)
            printf("s");
        printf("\n");
    }
}