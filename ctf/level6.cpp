/*
DHCTF{683_699_581_207_333_764_408_892_820_359_571_387_761_482_138_382_171_184_736_190_809_284_681_370_354_914_712_236_339_486}
{}内の10進数( _ で区切り)を16進数に変換し、それを降順に並び変えたものが答えです。

・16進数には頭に「0x」をつけること
・4桁になるよう0で埋めること
 
例：10進数の「15」→　0x000f, 10進数の「100」→　0x0064 

答え：DHCTF{0x0392_0x037c_0x0334_0x0329_0x02fc_0x02f9_0x02e0_0x02c8_0x02bb_0x02ab_0x02a9_0x0245_0x023b_0x01e6_0x01e2_0x0198_0x0183_0x017e_0x0172_0x0167_0x0162_0x0153_0x014d_0x011c_0x00ec_0x00cf_0x00be_0x00b8_0x00ab_0x008a}
*/


//解答例
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>

#define HEX(fill, wd) "0x"<<std::hex<<std::setfill(fill)<<std::setw(wd)     //16進数変換マクロ
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))               //配列数取得マクロ

int main()
{
    int num_box[] = {683, 699, 581, 207, 333, 764, 408, 892, 820, 359,
                     571, 387, 761, 482, 138, 382, 171, 184, 736, 190,
                     809, 284, 681, 370, 354, 914, 712, 236, 339, 486};
    int tmp;

    //配列内を降順にする
    for (int i = 0; i < SIZE_OF_ARRAY(num_box); i++)
    {
        for (int j = i + 1; j < SIZE_OF_ARRAY(num_box); j++)
        {
            if (num_box[i] < num_box[j])
            {
                tmp = num_box[i];
                num_box[i] = num_box[j];
                num_box[j] = tmp;
            }   
        }
    }

    //16進数に変換
    std::cout << "DHCTF{";
    for (int i = 0; i < SIZE_OF_ARRAY(num_box); i++)
    {
        std::cout << HEX('0', 4) << num_box[i] << "_";
    }
    std::cout << "}\n";
}