#include<bits/stdc++.h>
#include"WriteIn.h"
#include"Init.h"
#include"CCA.h"
#include"VCCA.h"

using namespace std;
int main()
{
	vector<ANS> data,test,train;
	
	int dim = 0, catoNum = 0;
	ReadData("iris", data, dim, catoNum);
	int n = data.size();
	int K =10;
	double finalr = 0;
	int M = 100;
	srand(time(0));
	for (int j = 1; j <= M; j++)
	{
		double rate = 0;
		for (int i = 1; i <= K; i++)
		{
			train.clear(); test.clear();
			int start = (n / K) * (i - 1);
			int end = (start + (n / K) * (K - 1)) % n;
			for (int i = start; i != end; i = (i + 1) % n)
			{
				train.push_back(data[i]);
			}
			for (int i = end; i != start; i = (i + 1) % n)
			{
				test.push_back(data[i]);
			}
			VCCA c(dim,catoNum,dim,10);
			//CCA c(dim, catoNum, dim);
			c.setTrain(train);
			c.train();
			c.setTest(test);
			rate += c.test();
		}
		printf("µÚ%d´Î,accuracy = %.6Lf\n", j,rate / K);
		finalr += rate / K;
	}
	printf("avarage accuracy = %.6Lf\n", finalr / M);
	return 0;
}