#include <iostream>

class A 
{
private:
    int value = -1;

public:
    void set_value(int value);
    int get_value() const;
    int get_value2() const;
};

void A::set_value(int value)
{
    this->value = value;
}

int A::get_value() const
{
    return value;
}

int A::get_value2() const
{
    return -(this->get_value());
}

int call_cl(A* pa)
{
    return pa->get_value() * 10;
}

int main()
{
    A a;

    a.set_value(5);
    std::cout << a.get_value() << std::endl;
    std::cout << a.get_value2() << std::endl;

    std::cout << call_cl(&a) << std::endl;
}