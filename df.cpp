#include"df.h"
#include<random>
int randi(int l, int r)
{
	int res = (int)((1.0 * rand() / (RAND_MAX+ 1)) * (r - l + 1)) + l;
	return res;
}