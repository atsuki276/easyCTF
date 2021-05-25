#include <iostream>
#include <string>

using namespace std;

string item_list[] = {
    "item1", "FLAG", "item1",
};

inline void end() {
    cout << "終了します\n";
}

int buy(int item) {
    int sum = 0;
    int kazu;

    cout << "いくつ買いますか?\n";
    cin >> kazu;

    sum = item * kazu;
    return sum;
}

int main()
{
    cout << "------------------------------\n";
    cout << "|" << item_list[0] << "|"
         << "|" << item_list[1] << "|"
         << "|" << item_list[2] << "|\n";
    cout << "------------------------------\n";

    int depo = 5000;
    int num = 1;

    while (num != 0)
    {
        cout << "財布：" << depo << "\n";
        cout << "数値を入力（0:終了, 1:購入）\n";
        cin >> num;

        switch (num)
        {
            case 1:
                depo -= buy(200);
                cout << "残高は" << depo << "\n\n";
                break;
            default:
                break;
        }

        if (depo <= 0)
        {
            cout << "残高がなくなりました\n";
            break;
        }
    }

    end();
}