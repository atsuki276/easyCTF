#include <iostream>
#include "car.h"

using namespace std;

int main()
{
	string name;
	int width, height, length;
	double gas;

	cout << "車のデータを入力してください。\n";
	cout << "車の名前:"; cin >> name;
	cout << "車幅:"; cin >> width;
	cout << "車高:"; cin >> height;
	cout << "長さ:"; cin >> length;
	cout << "gasolene:"; cin >> gas;

	Car myCar(name, width, height, length, gas);

	myCar.print_spec();

	while (true)
	{
		cout << "現在地 (" << myCar.x() << ", " << myCar.y() << ")\n";
		cout << "残り燃料:" << myCar.fuel() << "\n";

		cout << "どうしますか？（0：終了/1：移動/2:燃料を入れる）";
		int move;
		cin >> move;
		if (move == 0) break;
		
		if (move == 1)
		{
			double dx, dy;
			cout << "X方向の移動距離:"; cin >> dx;
			cout << "Y方向の移動距離:"; cin >> dy;

			if (!myCar.move(dx, dy))
			{
				cout << "燃料が足りません\n";
			}
		} else if (move == 2)
		{
			double gas_in;
			cout << "どのくらい入れますか:"; cin >> gas_in;
			myCar.gas_in(gas_in);
		}
	}
}