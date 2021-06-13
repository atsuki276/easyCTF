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
	std::cout << *sp << std::endl;

	std::string string = "testRiterall";
	const char* pstring = &string[0];
	
	pstring += 2;
	std::cout << *pstring << std::endl;
}