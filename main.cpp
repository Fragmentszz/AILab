#include<bits/stdc++.h>
#include"WriteIn.h"
#include"Init.h"
#include"CCA.h"

using namespace std;
int main()
{
	vector<ANS> data;
	ReadData("haberman",data);


	CCA c(3, 2, 2);
	c.setTrain(data);
	c.train();
	return 0;
}