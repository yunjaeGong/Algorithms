#include <iostream>
using namespace std;
#define ll long long 
const int MAX = 1000002;
ll A[MAX];

ll build(ll st[], int node, int l, int r) {
    if(l == r)
        return st[node] = A[l];
    int m = (l+r)/2;
    // A배열 원소끼리 비교하고 인덱스를 st에 저장
    return st[node] = build(st, 2*node, l, m) + build(st, 2*node+1, m+1, r);
}

ll find(ll st[], int node, int ql, int qr, int rs, int re) { // 최소값 반환
    if(ql <= rs && qr >= re) // range가 Query의 일부인 경우
        return st[node];
    if(ql > re || qr < rs) // 범위 벗어난 경우
        return 0;
    int mid = (rs + re)/2;
    return find(st, 2*node, ql, qr, rs, mid) + find(st, 2*node+1, ql, qr, mid+1, re);
}

void update(ll st[], int node, int l, int r, int u_idx, ll val) {
    if(l == r && l == u_idx) { // 업데이트할 인덱스이면
        st[node] = val; // 업데이트
        A[u_idx] = val;
        return ;
    }
    // 업데이트할 인덱스가 포함되는 range만 방문
    int m = (l+r)/2;
    if(u_idx >= l && u_idx <= m)
        update(st, 2*node, l, m, u_idx, val);
    else
        update(st, 2*node+1, m+1, r, u_idx, val);
    st[node] = st[2*node] + st[2*node+1];
}

int main() {
    int N, M, K, a, b;
    ll c;
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1;i<=N;++i)
        scanf("%lld", &A[i]);
    ll *st = new ll[4*MAX];
    fill(st, st+4*MAX, 0);
    build(st, 1, 1, N);
    for(int i=0;i<M+K;++i) {
        scanf("%d%d%lld", &a, &b, &c);
        if(a == 1)
            update(st, 1, 1, N, b, c);
        else
            printf("%lld\n", find(st, 1, b, c, 1, N));
    }
}