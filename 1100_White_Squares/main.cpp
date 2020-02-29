#include <iostream>

int main() {
    char inp[9], cnt=0;
    bool w=true;
    for(int i=0;i<8;++i) {
        std::cin >> inp;
        for(int j=0;j<8;++j,w=!w)
            if(inp[j] == 'F' && w)
                cnt++;
        w=!w;
    }
    std::cout << (int)cnt;
}
