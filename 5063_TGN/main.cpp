#include <cstdio>

int main() {
    int N;
    char arr[3][17] = {"advertise", "does not matter", "do not advertise"};
    scanf("%d",&N);
    for(int i=0;i<N;++i) {
        int r,e,c;
        scanf("%d%d%d",&r,&e,&c);
        if(r < e-c)
            printf("%s\n",arr[0]);
        else if(r == e-c)
            printf("%s\n",arr[1]);
        else
            printf("%s\n",arr[2]);
    }
}