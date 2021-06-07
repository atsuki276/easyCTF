#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#define Block 1

void decode(char* dst)
{
    char cipherBlockTemp[Block];
    memset(cipherBlockTemp, 12345, Block);

    for (int i = 0; i < Block; i++)
    {
        dst[i] = dst[i] ^ cipherBlockTemp[i];
    }
    return;
}

int main()
{
    std::string fileName;

    std::cout << "暗号ファイル名を入力\n";
    getline(std::cin, fileName);
    std::ifstream ifs(fileName, std::ios::binary);

    std::string outFileName;
    std::cout << "出力するファイル名\n";
    getline(std::cin, outFileName);
    std::ofstream ofs(outFileName, std::ios::app | std::ios::binary);

    char data[Block];

    char initialData[Block];
    memset(initialData, 'I', Block);

    char dataTemp[Block];
    char cipherBlockPre[Block];
    char decodeBlock[Block];

    ifs.read(data, Block);
    memcpy(cipherBlockPre, data, Block);
    decode(data);

    for (int i = 0; i < Block; i++)
    {
        decodeBlock[i] = data[i] ^ initialData[i];
    }

    ofs.write(decodeBlock, Block);
    do
    {
        ifs.read(data, Block);
        memcpy(dataTemp, data, Block);

        decode(data);
        if (ifs.eof()) break;

        for (int i = 0; i < Block; i++)
        {
            decodeBlock[i] = data[i] ^ cipherBlockPre[i];
        }

        ofs.write(decodeBlock, Block);
        memcpy(cipherBlockPre, dataTemp, Block);
    } while (true);  
}