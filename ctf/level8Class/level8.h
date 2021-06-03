#ifndef ___Class_Xor
#define ___Class_Xor

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#define Block 1

class Xor {
private:
    std::string fileName;
    std::string outFileName;
    char data[Block];
    char dataInitial[Block];
    char cipherBlockPre[Block];
    char cipherBlock[Block];

    void cipher(char* dst) {
        char cipherBlockTemp[Block];
        //暗号鍵
        memset(cipherBlockTemp, 12345, Block);

        for (int i = 0; i < Block; i++)
        {
            dst[i] = dst[i] ^ cipherBlockTemp[i];
        }
        return;
    }

public:
    //コンストラクタ
    Xor(std::string inFile, std::string outFile){
        fileName = inFile;
        outFileName = outFile;
    }

    //XORで暗号化
    void lockFile() {
        std::ifstream ifs(fileName, std::ios::binary);
        std::ofstream ofs(outFileName, std::ios::app | std::ios::binary);

        //初期化ベクトル
        memset(dataInitial, 'I', Block);
        ifs.read(data, Block);
        for (int i = 0; i < Block; i++)
        {
            cipherBlock[i] = data[i] ^ dataInitial[i];
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
};

#endif