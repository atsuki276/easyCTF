#include <iostream>
#include <string>

class person
{
private:
    std::string m_name;
    int m_age;

    person(int age);

public:
    person();
    person(std::string name, int age);
    ~person();

    void set_name(std::string);
    void set_age(int age);

    std::string name() const;
    int age() const;
};

person::person(int age) : m_age(age)
{
    std::cout << "共通コンストラクタ呼び出し" << std::endl;
}

person::person()
    :person(-1)
{
    std::cout << "引数なしコンストラクタ呼び出し" << std::endl;
}

person::person(std::string name, int age)
    :person(age)
{
    std::cout << "引数付きコンストラクタ呼び出し" << std::endl;
    set_name(name);
}

person::~person()
{
    std::cout << "インスタンスの破棄" << std::endl;
}

void person::set_name(std::string name)
{
    m_name = name;
}

void person::set_age(int age)
{
    m_age = age;
}

std::string person::name() const
{
    return m_name;
}

int person::age() const
{
    return m_age;
}

int main()
{
    person alice("alice", 15);
    std::cout << alice.name() << std::endl;

    person john;
    john.set_age(20);
    std::cout << john.age() << std::endl;
}