#include <string>
#include <stdio.h>
#include <iostream>
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
    char* data = new char[size];
    ifs.read(data, size);

    //サイズを出力
    std::cout << "size = " << size << "\n";
    if (size >= 200)
    {
        std::cout << "サイズが大きすぎます\n";
        return 0;
    }
    
    for (int i = 1; i < size + 1; i++)
    {
        std::stringstream ss;
        /*16進数文字列に変換する
        　char型をASCIIではなく、数値で出力する場合は先頭に+を付ける*/
        ss << std::hex << +data[i - 1];

        std::string test = ss.str();
        //符号付きであるか判定する
        if (test.size() > 5)
        {
            //符号付きの場合fが付くため、fを削除する
            std::string test = ss.str().erase(0, 6);
            std::cout << test << " ";
        }
        else
        {
            //符号付きでない場合そのまま出力する
            std::cout << ss.str() << " ";
        }
        //16バイト毎に改行する
        if ((i % 16) == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << "\nEnd\n";
    delete data;
}