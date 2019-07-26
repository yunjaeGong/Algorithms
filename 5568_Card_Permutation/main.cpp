#include <iostream>
#include <string>
#include <set>
using namespace std;
int a[11], N, K;
bool visited[11];
set<string> comb;

auto P(int x, int cnt, string s) {
    if (cnt == K) return comb.insert(s); // k개 선택하면 끝
    for (int i = 0; i < N; i++) { // 선택 가능한 모든 원소에 대해
        if (!visited[i]) { // 이전에 선택된 원소는 다시 선택 안하도록
            visited[i] = true;
            P(i, cnt + 1, s + to_string(a[i]));
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> a[i];
    P(0, 0, "");
    cout << comb.size();
}
