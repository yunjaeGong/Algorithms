#include <cstdio>
#include <cstring>

char s[9];

bool isP() {
    int len = strlen(s);
    for(int idx=0;idx<len/2;++idx)
        if (s[idx] != s[len-idx-1])
            return false;
    return true;
}

int main() {
    scanf("%s", &s);
    while(strcmp(s, "0")) {
        printf("%s\n", isP()?"yes":"no");
        scanf("%s", &s);
    }
}
