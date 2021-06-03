#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#define Block 1

void cipher(char* dst) {
    char cipherBlockTemp[Block];
    memset(cipherBlockTemp, 'S', Block);

    for (int i = 0; i < Block; i++)
    {
        dst[i] = dst[i] ^ cipherBlockTemp[i];
    }
    return;
}

int main()
{
    std::string fileName;

    //バイナリファイルで読み込み
    std::cout << "ファイル名を入力\n";
    getline(std::cin, fileName);
    std::ifstream ifs(fileName, std::ios::binary);

    std::string outFileName;
    std::cout << "出力するファイル名を入力\n";
    getline(std::cin, outFileName);
    std::ofstream ofs(outFileName, std::ios::app | std::ios::binary);

    //読み込みデータ
    char data[Block];

    //初期化ベクトル
    char initailData[Block];
    memset(initailData, 'I', Block);

    char cipherBlockPre[Block];
    char cipherBlock[Block];

    ifs.read(data, Block);
    for (int i = 0; i < Block; i++)
    {
        cipherBlock[i] = data[i] ^ initailData[i];
    }

    cipher(cipherBlock);

    ofs.write(cipherBlock, Block);
    memcpy(cipherBlockPre, cipherBlock, Block);
    do
    {
        ifs.read(data, Block);
        if (ifs.eof()) break;
        for (int i = 0; i < Block; i++)
        {
            cipherBlock[i] = data[i] ^ cipherBlockPre[i];
        }
        cipher(cipherBlock);
        ofs.write(cipherBlock, Block);
        memcpy(cipherBlockPre, cipherBlock, Block);
    } while (true);
}