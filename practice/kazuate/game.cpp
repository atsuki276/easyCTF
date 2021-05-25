#include <ctime>
#include <cstdlib>
#include "kazuate.h"

using namespace std;

//staticはこのファイルでしか使わないという指定
static int ans = 0;

void initalize()
{
	srand(time(NULL));	
}

void gen_no()
{
	ans = rand() % (max_no + 1);
}

int judge(int cand)
{
	if (cand == ans)
	{
		return 0;
	} else if (cand > ans)
	{
		return 1;
	} else
	{
		return 2;
	}
}