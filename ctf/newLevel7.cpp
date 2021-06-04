#include <iostream>
#include <vector>
#include <iterator>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

using std::cout; using std::cin;
using std::vector; using std::endl; using std::copy;

int main() {
    //暗号鍵の入力
    int key(0);
    cout << "暗号鍵を入力\n";
    cin >> key;

    //フラグのASCII
    vector<char> flag {'D', 'H', 'C', 'T', 'F', '{', '\0'};
    cout << "FLAG ASCII: ";
    copy(flag.begin(), flag.end() - 1, std::ostream_iterator<int> (cout, " "));
    cout << "\n";

    //XORをしたフラグのASCII
    for (int i = 0; i < SIZE_OF_ARRAY(flag); i++)
    {
        flag[i] ^= key;
    }
    cout << "FLAG XOR ASCII: ";
    copy(flag.begin(), flag.end() - 1, std::ostream_iterator<int> (cout, " "));

    cout << "\nFLAG XOR LOCK: ";
    copy(flag.begin(), flag.end() - 1, std::ostream_iterator<char> (cout, " "));

    return EXIT_SUCCESS;
}