#include <iostream>
#include <string>
#include "level8.h"

using namespace std;

int main()
{
    string inFile, outFile;

    //バイナリファイルで読み込み
    cout << "ファイル名を入力\n";
    getline(cin, inFile);

    cout << "出力するファイル名を入力\n";
    getline(cin, outFile);

    Xor flag(inFile, outFile);
    flag.lockFile();
}