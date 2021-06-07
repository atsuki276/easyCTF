#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#define BLOCK 1

using namespace std;

int main()
{
    string inFile;
    cout << "入力するファイル" << endl;
    getline(cin, inFile);
    ifstream ifs(inFile);

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

    string outFile;
    cout << "出力するファイル" << endl;
    getline(cin, outFile);
    ofstream ofs(outFile, ios::app | ios::binary);

    for (int i = 0; i < size; i += 3)
    {
        char hexNum[] = {data[i], data[i + 1], '\0'};
        cout << string(hexNum) << endl;
        ofs.write(hexNum, size);
    }
    
    ofs.close();
    delete data;
    return 0;
}