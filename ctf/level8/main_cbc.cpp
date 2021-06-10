#include <iostream>
#include <string>
#include "header_cbc.hpp"

using namespace std;

int main()
{
    string inFile, outFile;
    int key;

    //バイナリファイルで読み込み
    cout << "ファイル名を入力\n";
    getline(cin, inFile);

    cout << "出力するファイル名を入力\n";
    getline(cin, outFile);

    cout << "暗号鍵を入力\n";
    cin >> key;

    //インスタンス
    Xor flag(inFile, outFile, key);
    flag.lockFile();
}