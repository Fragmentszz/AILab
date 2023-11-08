#include"VCCA.h"

VCCA::VCCA(int _dim, int _catoNum, ld _R,int Cnum):num(Cnum),dim(_dim),catoNum(_catoNum),maxR(_R)
{
	for (int i = 0; i < num; i++)
	{
		CCAs.push_back(CCA(dim, catoNum, dim));
	}
}

void VCCA::setTest(std::vector<ANS>& testdata)
{
	for (ANS& data : testdata)
	{
		if (data.dim != dim + 1) {
			printf("输入测试样例维度有误..\n");
			continue;
		}
		ANS X(dim + 1);
		ld nj = 0;
		for (int i = 0; i < dim; i++)
		{
			X[i] = data[i];
			nj += data[i] * data[i];
		}
		X[dim] = sqrtl(maxR * maxR - nj);
		int c = round(data[dim]);
		testX.push_back(X);
		testY.push_back(c);
	}
}

void VCCA::setTrain(std::vector<ANS>& traindata)
{
	for (int i = 0; i < CCAs.size(); i++)
	{
		CCAs[i].setTrain(traindata);
	}
}

void VCCA::train()
{
	for (int i = 0; i < CCAs.size(); i++)
	{
		CCAs[i].train();
	}
}

int VCCA::classify(ANS data)
{
	std::vector<int> voting(catoNum + 1, 0);
	for (int i = 0; i < num; i++)
	{
		int nowres = CCAs[i].classify(data);
		voting[nowres]++;
	}
	int res = 0, ans = 0;
	for (int i = 1; i <= catoNum; i++)
	{
		if (ans < voting[i])
		{	
			res = i;
			ans = voting[i];
		}
	}
	return res;
}
int VCCA::predict(ANS X)
{
	if (X.dim != dim)
	{
		using namespace std;
		printf("输入模型的向量长度有误\n");
		return -1;
	}
	ANS data(dim + 1);
	ld dot = 0;
	for (int i = 0; i < dim; i++)
	{
		data[i] = X[i];
		dot += X[i] * X[i];
	}
	data[dim] = sqrtl(maxR * maxR - dot * dot);
	return classify(data);
}


double VCCA::test()
{
	int right = 0, wrong = 0;
	for (int i = 0; i < testX.size(); i++)
	{
		int res = classify(testX[i]);
		if (res == testY[i])	right++;
		else wrong++;
	}
	return 1.0 * right / (right + wrong);

}