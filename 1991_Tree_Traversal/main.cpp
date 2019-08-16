#include <cstdio>
char tree[27][3];
void in_order(int idx) {
    if(tree[idx][0] != -1)
        in_order(tree[idx][0]);
    printf("%c",tree[idx][1]+'A');
    if(tree[idx][2] != -1)
        in_order(tree[idx][2]);
}

void post_order(int idx) {

    if(tree[idx][0] != -1)
        post_order(tree[idx][0]);
    if(tree[idx][2] != -1)
        post_order(tree[idx][2]);
    printf("%c",tree[idx][1]+'A');
}

void pre_order(int idx) {
    printf("%c",tree[idx][1]+'A');
    if(tree[idx][0] != -1)
        pre_order(tree[idx][0]);
    if(tree[idx][2] != -1)
        pre_order(tree[idx][2]);
}

int N;
int main() {
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;++i) {
        char Cur,L,R;
        scanf("%c %c %c",&Cur,&L,&R);
        getchar();
        tree[Cur-'A'][1] = Cur-'A';
        tree[Cur-'A'][0] = L=='.'?-1:L-'A';
        tree[Cur-'A'][2] = R=='.'?-1:R-'A';
    }
    pre_order(0);
    printf("\n");
    in_order(0);
    printf("\n");
    post_order(0);
}