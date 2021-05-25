double power(double x, int n)
{
	double tmp = 1.0;

	for (int i = 0; i < n; i++)
	{
		tmp *= x;
	}
	return tmp;
}