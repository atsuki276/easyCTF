#include <iostream>
#include <string>

void output(char* str)
{
    std::cout << *str << std::endl;
    str++;
    *str = 'v';
    std::cout << *str << std::endl;
    str++;
    std::cout << *str << std::endl;
}

int main()
{
    std::string test = "abc";
    output(&test[0]);
    std::cout << test << std::endl;
}
