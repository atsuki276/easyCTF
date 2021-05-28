#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	time_t current = time(NULL);
	struct tm* timer = localtime(&current);
	char* wday_name[] = {"“ú", "Œ", "‰Î", "…", "–Ø", "‹à", "“y"};

	cout << "Œ»İ‚Ì“ú•tE‚Í"
		 << timer->tm_year + 1900 << "”N";
	
}