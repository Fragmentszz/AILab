#pragma once
#include"ANS.h"

class Cover
{
protected:
	ANS center;
	ld radis;
public:
	Cover(ANS _center,ld _r);

	friend class CCA;
};

class CCA
{
protected:
	int dim;
	int catoNum;
	int trainNum, testNum;
	int ntrain;
	ld maxR;
	std::vector<ANS> InPutLayer, OutPutLayer, HiddenLayer;
	std::vector<ANS> trainX,testX;
	std::vector<int> trained;
	std::vector<int> trainY,testY;
	std::vector<std::set<int>> cato_train;
	std::vector<std::vector<Cover>> Covers;
	int classify(ANS data);
public:
	CCA(int _dim,int _catoNum,ld _R);
	int predict(ANS X);
	void setTrain(std::vector<ANS>& traindata);
	void setTest(std::vector<ANS>& testdata);
	void train();
	double test();
	friend class VCCA;
};