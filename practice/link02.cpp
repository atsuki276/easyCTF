#include <iostream>

using namespace std;

double power(double x, int n);

int main()
{
	double a;
	int b;

	cout << "a‚Ìbæ‚ð‹‚ß‚Ü‚·\n";
	cout << "ŽÀ”a:"; cin >> a;
	cout << "®”b:"; cin >> b;

	cout << a << "‚Ì" << b << "æ‚Í" <<
	power(a, b) << "‚Å‚·\n";
}