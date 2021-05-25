#include <iostream>
#include "kazuate.h"

using namespace std;

int max_no = 9;

int main()
{
	initalize();
	cout << "”“–‚ÄƒQ[ƒ€ŠJŽn\n";

	do
	{
		gen_no();
		int hantei;
		do
		{
			hantei = judge(input());
			if (hantei == 1)
			{
				cout << "‚à‚Á‚Æ¬‚³‚¢‚Å‚·\n";
			} else if (hantei == 2)
			{
				cout << "‚à‚Á‚Æ‘å‚«‚¢‚Å‚·\n";
			}

		} while (hantei != 0);
		cout << "³‰ð‚Å‚·\n";
	} while (confirm_retry());
	
}