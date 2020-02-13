#include<iostream>
#include<cstring>
int main() {
    char arr[101];
    std::cin >> arr;
    int len = strlen(arr);

    for (int i = 0; i < len; i++) {
        std::cout << arr[i];
        if ((i + 1) % 10 == 0)
            std::cout <<'\n';
    }
}