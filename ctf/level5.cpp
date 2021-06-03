/**
 * HLGXJ{xlmwmw_Geiwev_uyiwxmsr}
 * ↑のシーザー暗号の解読問題
 * 4文字次にずらしている。
 * 
 * 下記のコードは解答例
 * 
 * */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char flag[] = "HLGXJ{xlmwmw_Geiwev_uyiwxmsr}";

    for (int i = 0; i < strlen(flag); i++)
    {
        //記号は無視
        if (flag[i] == '{' || flag[i] == '_' || flag[i] == '}')
        {
            continue;
        }

        //4文字前に戻して出力
        flag[i] -= 4;
        cout << flag[i];
        
    }
    
}