/*
brokenFlag.jpg
フラグを折ってしまいました。
バイナリの1バイトずつに1を足してあげると直ります。
*/

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

int main()
{
    //読み込むファイル
    std::string inFile;
    std::cout << "入力ファイル名を入力\n";
    getline(std::cin, inFile);
    std::ifstream ifs(inFile, std::ios::binary);

    //読込サイズを調べる。
    ifs.seekg(0, std::ios::end);
    long long int size = ifs.tellg();
    ifs.seekg(0);
    if (size >= 30000)
    {
        std::cout << "サイズが大きすぎます\n";
        return 0;
    }

    //出力ファイル
    std::string outFile;
    std::cout << "出力ファイル名を入力\n";
    getline(std::cin, outFile);
    std::ofstream outputfile(outFile, std::ios::app | std::ios::binary);

    //読み込んだデータをchar型に出力する
    char *data = new char[size];
    ifs.read(data, size);

    //サイズを出力する
    std::cout << "size = " << size << std::endl;

    std::cout << std::hex << int(data[0]) << std::endl;
    std::cout << std::hex << int(data[1]) << std::endl;
    std::cout << std::hex << int(data[2]) << std::endl;
    std::cout << std::hex << int(data[3]) << std::endl;

    outputfile.write(data, size);
    std::cout << "End!" << std::endl;
    outputfile.close();
    delete data;
}