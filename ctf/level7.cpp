/*
排他的論理和の問題（未完成）
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>

#define HEX(fill, wd) "0x"<<std::hex<<std::setfill(fill)<<std::setw(wd)

int main() {
    int a, b, c, flag;

    a = 12598756;
    flag = 56812369;

    b = a ^ flag;
    std::cout << b << "\n";
    //std::cout << HEX('0', 4) << b << "\n";

    c = b ^ flag;
    std::cout << c << "\n";
    //std::cout << HEX('0', 4) << c << "\n";
}