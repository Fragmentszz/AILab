#include"df.h"
#include<random>
int randi(int l, int r)
{
	return (int)((1.0 * rand() / RAND_MAX) * (r - l + 1)) + l;
}