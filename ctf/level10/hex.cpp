/*
バイナリファイルを16進数で表示
*/

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

int main()
{
    //ファイルをバイナリで読み込む
    std::string fileName;
    std::cout << "ファイル名を入力\n";
    getline(std::cin, fileName);
    std::ifstream ifs(fileName, std::ios::binary);

    //読み込みサイズを調べる。
    ifs.seekg(0, std::ios::end);
    long long int size = ifs.tellg();
    ifs.seekg(0);

    //データをcharに変換
    char *data = new char[size];
    ifs.read(data, size);

    //サイズを出力
    std::cout << "size = " << size << "\n";
    if (size >= 30000)
    {
        std::cout << "サイズが大きすぎます\n";
        return -1;
    }

    //出力ファイル
    std::string outFile;
    std::cout << "出力するファイル名" << std::endl;
    getline(std::cin, outFile);
    std::ofstream ofs(outFile, std::ios::app);

    for (int i = 1; i < size + 1; i++)
    {
        std::stringstream ss;
        /*16進数文字列に変換する
        　char型をASCIIではなく、数値で出力する場合は先頭に+を付ける*/
        ss << std::hex << std::setfill('0') << std::setw(2) << +data[i - 1];

        //符号付きでない場合そのまま出力する
        std::cout << ss.str() << " ";
        ofs << std::setfill('0') << std::setw(2) << ss.str() << " ";
        //16バイト毎に改行する
        if ((i % 16) == 0) std::cout << "\n";
    }
    std::cout << "\nEnd\n";
    ofs.close();
    delete data;
}