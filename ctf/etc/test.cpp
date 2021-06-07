#include <iostream>
#include <fstream>

#define ArraySize(array) (sizeof(array)/sizeof(array[0])) 
#define F "test.txt"

using namespace std;

int main()
{
    char inputTxt[3];
    ofstream outputfile(F);

    for (int i = 0; i <= ArraySize(inputTxt); i++)
    {
        if (i == ArraySize(inputTxt))
        {
            inputTxt[i] = '\0';
            break;
        }
        cout << "‰½‚©•¶Žš‚ð‹L“ü‚µ‚Ä‚­‚¾‚³‚¢B:";
        cin >> inputTxt[i];
        cout << "‚ ‚È‚½‚ª‹L“ü‚µ‚½•¶Žš" << inputTxt[i] << endl;
    }
    outputfile << inputTxt;
    outputfile.close();
}