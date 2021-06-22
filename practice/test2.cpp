#include <iostream>
#include <string>
#include <functional>

int main()
{
    int x;

    // char型の値'C'に対するハッシュ値を求める
    std::cout << std::hash<std::string>()("Hello") << std::endl;

    // int型の値100に対するハッシュ値を求める
    std::cout << std::hash<int>()(50) << std::endl;

    // double型の値3.14に対するハッシュ値を求める
    std::cout << std::hash<double>()(3.14) << std::endl;

    // int*型のアドレス値(&x)に対するハッシュ値を求める
    std::cout << std::hash<int *>()(&x) << std::endl;
}