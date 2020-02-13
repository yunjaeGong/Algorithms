#include <iostream>

using namespace std;
struct mm {int Min, Max;};
mm st[300000];
int A[100001];

mm build(int node, int l, int r) {
    if(l == r) {
        return st[node] = {l, l};
    }
    int mid = (l + r)/2;
    mm L = build(2*node, l, mid);
    mm R = build(2*node+1, mid+1, r);
    // A배열 원소끼리 비교하고 인덱스를 st에 저장

    st[node].Min = (A[L.Min] > A[R.Min])?R.Min:L.Min;
    st[node].Max = (A[L.Max] > A[R.Max])?L.Max:R.Max;
    return st[node];
}

// 쿼리와 답, 값을 반환
mm find(int node, int ql, int qr, int rs, int re) {
    if(ql <= rs && qr >= re) // range가 query의 일부이면!
        return { A[st[node].Min], A[st[node].Max] };
    if(ql > re || qr < rs) // out of range
        return {-1, -1};

    int rm = (rs + re)/2;
    mm L = find(2*node, ql, qr, rs, rm);
    mm R = find(2*node+1, ql, qr, rm+1, re);
    if(L.Max == -1)
        return R;
    else if(R.Max == -1)
        return L;
    else
        return { min(L.Min, R.Min), max(L.Max, R.Max) };
}

int main() {
    cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);
    int N, M, ql, qr;
    cin >> N >> M;
    for(int i=1;i<=N;++i)
        cin >> A[i];
    build(1,1,N);
    for(int i=1;i<=M;++i) {
        cin >> ql >> qr;
        mm res = find(1,ql,qr,1,N);
        cout << res.Min << " " << res.Max << '\n';
    }
}