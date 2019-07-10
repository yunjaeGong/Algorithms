#include <cstdio>
int main() {
    int o,f,s=0,max=0;
    for(int i=0;i<4;++i) {
        scanf("%d%d",&f,&o);
        s += o; s-=f;
        if(max < s) max = s;
    }
    printf("%d",max);
}