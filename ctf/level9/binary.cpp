#include <string>
#include <stdio.h>
#include <iostream>
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
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i - 1] << " ";
        if ((i % 16) == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << "\nEnd\n";
    delete data;
}