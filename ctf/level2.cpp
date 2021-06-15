/**
 * @file level2.cpp
 * 文字連結、コピーなど
 */

#include <iostream>
#include <cstring>

using namespace std;

void checker(char check1[], char* check2)
{
    if(strcmp(check1, check2) == 0) {
        cout << "It's a flag!";
    } else {
        cout << "No Flag";
    }
}

int main()
{
    char str0[20] = "DHCTF{faB";
    char str1[20] = "DHCTF{G";
    char str2[20] = "Hn_adj";
    char str3[20] = "jf}_Adp}";
    const char* str4 = "dBa}n_G}";
    char youFlag[20];

    strncpy(str3, str4, 5);
    strncat(str2, str3, 4);
    strcpy(str0, strcat(str1, str2));

    cout << "Input your flag.\n";
    cin >> youFlag;

    checker(str0, youFlag);
}