#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char arr[260];
    while(1) {
        long long sum = 0;
        cin.getline(arr,257,'\n');
        int len = strlen(arr);
        if(arr[0] == '#') {
            fflush(stdout);
            return 0;
        } else {
            for(int i=0;i<len;++i) {
                if(arr[i] == ' ')
                    continue;
                sum += (i+1) * (arr[i]-'A'+1);
            }
            printf("%lld\n",sum);
        }
    }
}