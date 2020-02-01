#include <iostream>
using namespace std;
const int MAX = 100002, INF = 1<<30;
int A[MAX];

int build(int st[], int node, int l, int r) {
    if(l == r) {
        return st[node] = l;
    }
    int m = (l+r)/2;
    l = build(st, 2*node, l, m);
    r = build(st, 2*node+1, m+1, r);
    // A배열 원소끼리 비교하고 인덱스를 st에 저장
    return st[node] = A[l] > A[r]?r:l; 
}

int find(int st[], int node, int ql, int qr, int rs, int re) { // 최소값 반환
    if(ql <= rs && qr >= re) // range가 Query의 일부인 경우
        return A[st[node]];
    if(ql > re || qr < rs) // 범위 벗어난 경우
        return INF;
    int mid = (rs + re)/2;
    return min(find(st, 2*node, ql, qr, rs, mid), find(st, 2*node+1, ql, qr, mid+1, re));
}

void update(int st[], int node, int l, int r, int u_idx, int val) {
    if(l == r == u_idx) { // 업데이트할 인덱스이면
        A[u_idx] = val; // 업데이트
        return ;
    }
    // 업데이트할 인덱스가 포함되는 range만 방문
    int m = (l+r)/2;
    if(u_idx >= l && u_idx <= m)
        update(st, 2*node, l, m, u_idx, val);
    if(u_idx >= m+1 && u_idx <= r)
        update(st, 2*node+1, m+1, r, u_idx, val);
    st[node] = A[st[2*node]] > A[st[2*node+1]]?st[2*node+1]:st[2*node];
}

int main() {
    int N, M, a, b;
    scanf("%d%d", &N, &M);
    for(int i=1;i<=N;++i)
        scanf("%d", &A[i]);
    int *st = new int [4*MAX];
    fill(st, st+2*MAX, INF);
    build(st, 1,1,N);
    for(int i=0;i<M;++i) {
        scanf("%d%d", &a, &b);
        printf("%d\n", find(st, 1, a, b, 1, N));
    }
}