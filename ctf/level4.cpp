#include <iostream>
#include <string>

using namespace std;

string item_list[3][3] = {
    {"1", "apple", " 100",},
    {"2", "FLAG", "50000",},
    {"3", "orange", "200",},
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
    cout << sum << "円使いました\n\n";
    return sum;
}

int main()
{
    int depo = 5000;
    int num = 1;

    while (num != 0)
    {

        cout << "--------------------\n";
        for (int i = 0; i < 3; i++)
        {
                cout << "|" << item_list[i][0] << "  " << item_list[i][1] << "  " << item_list[i][2] << " 円 |\n";
        }
        cout << "--------------------\n";

        cout << "財布：" << depo << "\n";
        cout << "どれを買いますか？（番号を選択、0で終了）\n";
        cin >> num;

        switch (num)
        {
            case 1:
                depo -= buy(100);
                cout << "残高は" << depo << "\n\n";
                break;
            case 2:
                if (depo < 50000)
                {
                    cout << "お金が足りません！\n\n";
                } else {
                    depo -= 50000;
                    cout << "Thanks!\n" << "DHCTF{lNEkn_nakna_RqpJs}\n";
                }
                break;
            case 3:
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