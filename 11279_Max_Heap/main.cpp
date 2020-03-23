#include <iostream>
#define ui unsigned int
unsigned int heap[200002];
ui last;
inline void swap(ui &a, ui &b) { ui t=a; a=b; b=t; }
int main() {
    int N, in;
    ui i;
    scanf("%d",&N);
    for(int k=0;k<N;++k) {
        scanf("%d",&in);
        if(in) { // push
            heap[last+1] = in;
            last++;
            i=last;
            while(i>1) {
                if(heap[i/2] >= heap[i]) // 부모가 자신보다 크면
                    break;
                swap(heap[i/2], heap[i]);
                i/=2;
            }
        }
        else { // pop
            ui max = 0, next;
            if(last != 0) {
                max = heap[1];
                heap[1] = heap[last];
                heap[last] = 0;
                last--;
                i = 1;
                while(i<last) {
                    ui L = 2*i, R = 2*i+1;
                    if(L>last) break;
                    if(heap[L] < heap[i] && heap[R] < heap[i])
                        break;
                    if(heap[L] > heap[i] && heap[L] >= heap[R])
                        next = L;
                    else if(heap[R] > heap[i] && heap[R] >= heap[L])
                        next = R;
                    else break;
                    swap(heap[next], heap[i]);
                    i = next;
                }
            }
            printf("%d\n",max);
        }
    }
}
