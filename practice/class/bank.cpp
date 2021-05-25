#include <iostream>
#include <string>

using namespace std;

class Account {
	private:
		string full_name;
		string number;
		long crnt_balance;

	public:
		Account(string name, string num, long amnt) {
			full_name = name;
			number = num;
			crnt_balance = amnt;
		}

		//口座名義出力
		string name() {
			return full_name;
		}

		//口座番号出力
		string no() {
			return number;
		}

		//残高出力
		long balance() {
			return crnt_balance;
		}

		//預ける
		void deposit(long amnt) {
			crnt_balance += amnt;
		}

		//おろす
		void withdraw(long amnt) {
			crnt_balance -= amnt;
		}
};

int main()
{
	Account suzuki("鈴木", "12345", 1000);
	Account tanaka("田中", "67890", 2000);

	suzuki.withdraw(500);
	tanaka.deposit(700);

	cout << "鈴木口座" << suzuki.name() << suzuki.no() << suzuki.balance() << "\n";
	cout << "田中口座" << tanaka.name() << tanaka.no() << tanaka.balance() << "\n";
}