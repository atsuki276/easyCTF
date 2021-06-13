#include <iostream>
#include <string>

int main()
{
	std::string str[] = {"paul", "X", "MAC"};
	const std::string* sp = str;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "p[" << i << "] = " << str[i] << std::endl;
	}

	sp++;
	std::cout << *sp;
	
}