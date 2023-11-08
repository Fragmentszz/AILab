#include"CCA.h"

Cover::Cover(ANS _center, ld _r) :center(_center), radis(_r)
{

}

void CCA::setTrain(std::vector<ANS>& traindata)
{
	trainNum = 0;
	trainX.clear();
	trainY.clear();
	trained.clear();
	for (ANS& data : traindata)
	{
		if (data.dim != dim + 1) {
			printf("输入训练样例维度有误..\n");
			continue;
		}
		ANS X(dim+1);
		ld nj = 0;
		for (int i = 0; i < dim; i++)
		{
			X[i] = data[i];
			nj += data[i] * data[i];
		}
		X[dim] = sqrtl(maxR * maxR - nj);
		int c = round(data[dim]);
		trainX.push_back(X);
		trainY.push_back(c);
		trained.push_back(0);
		cato_train[c].insert(trainNum++);
	}
	ntrain = trainNum;
}

void CCA::setTest(std::vector<ANS>& testdata)
{
	testNum = 0;
	for (ANS& data : testdata)
	{
		if (data.dim != dim + 1) {
			printf("输入测试样例维度有误..\n");
			continue;
		}
		ANS X(dim+1);
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
		testNum++;
	}
}

CCA::CCA(int _dim, int _catoNum,ld _R) :dim(_dim), catoNum(_catoNum), trainNum(0), testNum(0),ntrain(0),maxR(_R)
{
	//std::cout << "dim = " << dim << std::endl;
	cato_train.resize(_catoNum + 5);
	Covers.resize(_catoNum + 5);
}

void CCA::train()
{
	srand(time(0));
	int cnt = 0;
	while (1)
	{
		using namespace std;
		bool empty = 1;
		std::vector<int> nempty;
		for (int i = 1; i <= catoNum; i++)
		{
			if (!cato_train[i].empty()) {
				empty = 0;
				nempty.push_back(i);
			}
		}
		if (empty)	break;
		int nowcato = nempty[randi(0, nempty.size() - 1)];
		if (0)							//只有一类
		{

		}
		else
		{
			int nowcenterid = randi(0, cato_train[nowcato].size() - 1);
			
			auto ite = cato_train[nowcato].begin();
			for (; nowcenterid > 0; nowcenterid--)	ite++;
			int nowcenter = *ite;
			ld mindot = trainX[nowcenter] * trainX[nowcenter];
			ld maxdot = -INFINITY;
			for (int other : nempty)
			{
				if (other == nowcato) {
					continue;
				}
				for (int othercenter : cato_train[other])
				{
					maxdot = max(maxdot, trainX[nowcenter] * trainX[othercenter]);
				}
			}
			//ntrain--;
			//if (maxdot - mindot > 0)	cout << maxdot << " ???  " << mindot << endl;
			std::vector<int> removed;
			for (int same : cato_train[nowcato])
			{
				ld dis = trainX[same] * trainX[nowcenter];
				if (dis >= maxdot)
				{
					mindot = min(dis, mindot);
					removed.push_back(same);
					ntrain--;
				}
			}
			if (maxdot < -(trainX[nowcenter]*trainX[nowcenter]))		//没有其他类别
			{
				maxdot = mindot *0.5;									//此处可改,当没有其他类别时，距离的最大范围
			}
			if (mindot <= maxdot)	cout << mindot << " " << maxdot << endl;
			ld r = 0.5 * (maxdot + mindot);
			Cover newcover = Cover(trainX[nowcenter],r);
			Covers[nowcato].push_back(newcover);
			for (int t : removed)
			{
				cato_train[nowcato].erase(t);
			}
			std::cout << nowcato << " " << r << " ";
			trainX[nowcenter].print();
			cnt++;
			int numsum = 0;
			for (auto z : cato_train)
			{
				numsum += z.size();
			}
			//cout << numsum << endl;
		}
	}
	std::cout << "共产生" << cnt << "个cover" << std::endl;
}

void CCA::test()
{

}