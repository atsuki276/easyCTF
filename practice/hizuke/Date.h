#include <iostream>
#include <string>

class Date
{
private:
	int y;
	int m;
	int d;

public:
	Date();								//デフォルトコンストラクタ
	Date(int yy, int mm, int dd);		//コンストラクタ
	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }

	Date preceding_day() const;			//前日の日付を返却

	std::string to_string() const;		//文字列表現を返却
};

std::ostream& operator<<(std::ostream& s, const Date& x);	//挿入子
std::istream& operator>>(std::istream& s, Date& x);			//抽出子