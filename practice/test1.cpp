#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));

	int no = rand() % 100;
	int x;

	cout << "”“–‚ÄƒQ[ƒ€\n";
	cout << "0~99‚Ì”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n";

	do {
		cin >> x;

		if(x > no) {
			cout << "‚à‚Á‚Æ¬‚³‚È”‚Å‚·";
		} else if(x < no) {
			cout << "‚à‚Á‚Æ‘å‚«‚È”‚Å‚·";
		}
	} while (x != no);

	cout << "³‰ð‚Å‚·";
}