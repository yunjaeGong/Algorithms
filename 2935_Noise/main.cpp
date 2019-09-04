#include <cstdio>
#include <string.h>
int main() {
    char arr_1[202], arr_2[202], op;
    scanf("%s",arr_1);
    getchar();
    scanf("%c",&op);
    getchar();
    scanf("%s",arr_2);
    int len_1 = strlen(arr_1), len_2 = strlen(arr_2);
    if(op == '*') {
        int i=0;
        for(;i<len_2-1;++i)
            arr_1[len_1+i] = '0';
        arr_1[len_1+i] = 0;
        printf("%s",arr_1);
    } else {
        if(len_1 >= len_2) {
            arr_1[len_1-len_2] += 1;
            printf("%s",arr_1);
        } else {
            arr_2[len_2-len_1] += 1;
            printf("%s",arr_2);
        }
    }
}