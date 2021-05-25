/**
 * @file test2.cpp
 * @author au
 * @brief 
 * @version 0.1
 * @date 2021-05-07
 * 
 * @copyright Copyright (c) 2021
 * 
 * x++と++xの違いを調べるためのカウントダウン処理
 */

#include <iostream>

using namespace std;

int main() 
{
	int x;

	cout << "number\n";
	do {
		cin >> x;
	} while (x <= 0);

	cout << "\nCountDown\n";
	while (x >= 0)
	{
		cout << --x << "\n";
	}
}