#include <iostream>

using namespace std;

int seq_search(int* a, int n, int key)
{
	int* p = a;

	while (n-- > 0)
	{
		if (*p == key)
		{
			return p - a;
		} else {
			p++;
		}
	}
	return -1;
}

int main()
{
	int key, idx;
	int x[7];
	int x_size = sizeof(x) / sizeof(x[0]);

	for (int i = 0; i < x_size; i++)
	{
		cout << "x[" << i << "]:";
		cin >> x[i];
	}
	cout << "’T‚·’l‚Í\n";
	cin >> key;

	if ((idx = seq_search(x, x_size, key)) != -1)
	{
		cout << "’l‚Í" << idx;
	} else {
		cout << "Œ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½";
	}
}