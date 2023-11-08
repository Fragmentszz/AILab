#pragma once
#include"df.h"
#include"CCA.h"
class VCCA
{
private:
	int num;
	int dim;
	int catoNum;
	ld maxR;
	std::vector<CCA> CCAs;
	std::vector<int> testY;
	std::vector<ANS> testX;
	int classify(ANS X);
public:
	VCCA(int _dim, int _catoNum, ld _R,int CNUM);
	void setTrain(std::vector<ANS>& traindata);
	void setTest(std::vector<ANS>& testdata);
	void train();
	double test();
	int predict(ANS X);
	
};