/*
brokenFlag.jpg
フラグを折ってしまいました。
*/

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>

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
    std::reverse(data, data + size);
    outputfile.write(data, size);
    std::cout << "End!" << std::endl;
    outputfile.close();
    delete data;
}