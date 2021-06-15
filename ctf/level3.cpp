/**
 * @file level3.cpp
 * —áŠOˆ—
 */

#include <iostream>
#include <new>

using namespace std;

int main()
{
    int obj;
    char flag[] = "DHCTF{you_can_reiGaiSyori}";
    cout << "—v‘f”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n";
    cin >> obj;

    while (1) {
        try {
            double* a = new double[obj];
            cout << "—v‘f‚ğ" << obj << "ŒÂ¶¬";
            return 0;
        }
        catch (bad_alloc) {
            cout << flag;
            return 1;
        }
    }
}