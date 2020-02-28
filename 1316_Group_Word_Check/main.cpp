#include <iostream>
#include <cstring>
using namespace std;
char arr[101];
bool check[26], flag;
int main() {
    int t, cnt = 0;
    cin >> t;
    while(t) {
        flag = false;
        cin >> arr;
        int size = strlen(arr);
        for(int i=0;i<size-1;++i) {
            if(arr[i] != arr[i+1]) {
                if(!check[arr[i]-'a'])
                    check[arr[i]-'a'] = true;
            }
        }
        cnt++;
    }
    cout << cnt;
}
