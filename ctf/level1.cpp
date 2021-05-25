/**
 * ‹e’r‚³‚ñ‚Ì‚ğ^—‚½‚¾‚¯
 */

#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
	char flag[] = {'D','H','C','T','F','{','e','a','s','y','_','s','t','r','i','n','g','s','}','\0'};
	char str[20];

	cout << "Input your flag.\n";
	cin >> str;

	if(strcmp(flag, str) == 0) {
		cout << "it's Flag";
	} else {
		cout << "no Flag";
	}
}