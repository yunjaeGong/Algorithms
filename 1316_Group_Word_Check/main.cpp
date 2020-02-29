#include <iostream>
#include <cstring>
using namespace std;
char arr[101];
bool check[26], flag;
int main() {
    int t, cnt = 0;
    cin >> t;
    while(t--) {
        flag = false;
        memset(check, 0, 26);
        cin >> arr;
        int size = strlen(arr);
        for(int i=1;i<size;++i) {
            if(arr[i-1] != arr[i] &&check[arr[i]-'a']) {
                flag = true;
                break;
            }
            check[arr[i-1]-'a'] = true;
        }
        if(!flag)
            cnt++;
    }
    cout << cnt;
}
