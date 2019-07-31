#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> getPi(string p)
{
    int m = (int)p.size();
    int j = 0;

    vector<int> pi(m, 0);

    for (int i = 1; i< m; i++) {
        j = pi[i-1]; // 새로운 공통 문자열의 최대 길이는 pi[i-1]로 초기화
        while (j > 0 && p[i] != p[j]) // 다르면 공통 문자열의 길이를 줄여
            j = pi[j - 1]; // 새로운 j는 j-1까지의 공통 문자열(접미사와 접두사)의 길이와 같다.
        if (p[i] == p[j]) // 줄인 공통 문자열의 (맨 끝)i와 j가 같으면
            pi[i] = j+1; // 공통 문자열 길이는 j+1
    }
    return pi;
}

vector<int> getF(string p) {
    int m = (int)p.size(); // 패턴 문자열의 길이
    int j = 0;

    vector<int> F(m, 0);
    for(int i=0;i<m;++i) {
        // 새로운 공통 문자열의 최대 길이는 F[i-1]로 초기화
        j = F[i-1];
        while(j>0 && p[i] != p[j]) // prefix와 suffix의 마지막 (끝과 시작)원소가 다를때만
            // 접두/접미사 공통 문자열을 줄여서 공통 문자열을 찾는다
            // 길이가 j-1인
        if(p[i] == p[j]) // prefix와 suffix의 마지막 (끝과 시작)원소가 같으면
            p[i] = j+1;
    }
}
vector<int> kmp(string T, string P) {
    vector<int> ans;
    auto pi = getPi(P);
    int n = (int)T.size(), m = (int)P.size(), j = 0;
    for(int i=0;i<n;++i) {
        // T[i] != P[j] 이면
        while(j!=0 && P[j] != T[i])
            j = pi[j-1];
        if(T[i] == P[j]) {
            if(j == m-1) // matching 문자열 찾음
                ans.push_back(i - m+1); // 패턴 시작 위치 추가
            else
                j++; // 같지만 pattern 시작 위치가 아니면 j증가
        }
    }
    return ans;
}

int main() {
    string P, T;
    // scanf("%s%s",&P,&T);
    cin >> P >> T;
    auto ans = kmp(T,P);
    for(auto e:ans) {
        printf("%d ",e);
    }
}

// https://www.crocus.co.kr/559 참고한 알고리즘