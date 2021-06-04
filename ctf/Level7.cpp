/*
XORの問題
フラグと鍵を入力した後、二つでXORを行い、その結果を出力する
*/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::cout; using std::cin; using std::string;
using std::vector; using std::endl; using std::copy;

int main() {
    
    //暗号化したいフラグ
    string flag;
    cout << "フラグを入力\n";
    cin >> flag;

    //暗号鍵の入力
    int key(0);
    cout << "暗号鍵を入力\n";
    cin >> key;

    vector<char> asciiFlag(flag.begin(), flag.end());

    cout << "\nFLAG: ";
    copy(asciiFlag.begin(), asciiFlag.end(), std::ostream_iterator<char>(cout, ""));

    //フラグのASCII
    cout << "\nFLAG ASCII: ";
    copy(asciiFlag.begin(), asciiFlag.end(), std::ostream_iterator<int> (cout, " "));
    cout << "\n";

    //XORをしたフラグのASCII
    for (int i = 0; i < asciiFlag.size(); i++)
    {
        asciiFlag[i] ^= key;
    }
    cout << "FLAG XOR ASCII: ";
    copy(asciiFlag.begin(), asciiFlag.end(), std::ostream_iterator<int> (cout, " "));

    //暗号化されたフラグ
    cout << "\nFLAG XOR LOCK: ";
    copy(asciiFlag.begin(), asciiFlag.end(), std::ostream_iterator<char> (cout, ""));

    return EXIT_SUCCESS;
}