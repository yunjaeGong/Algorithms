#include <iostream>
#include <set>
using namespace std;

struct StringCompare{
    bool operator () (const std::string& s_left, const std::string& s_right) {
        return s_left.size() == s_right.size() ? s_left.compare(s_right) < 0 : s_left.size() < s_right.size();
    }
};

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    set<string, StringCompare> S;
    string s;
    for(int i=0;i<N;++i) {
        cin >> s;
        S.insert(s);
    }
    for(const string &e:S) {
        cout << e << '\n';
    }
}