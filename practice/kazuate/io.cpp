#include <iostream>
#include "kazuate.h"

using namespace std;

static void prompt()
{
	cout << "0~" << max_no << "‚Ì”:";
}

int input() {
	int val;
	do
	{
		prompt();
		cin >> val;
	} while (val < 0 || val > max_no);
	return val;
}

bool confirm_retry()
{
	int cont;
	cout << "‚à‚¤ˆê“x‚µ‚Ü‚·‚©?\n" << "Yes:1/No:0\n";
	cin >> cont;
	return static_cast<bool>(cont);
}