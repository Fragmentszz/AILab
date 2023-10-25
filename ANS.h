#pragma once
#include"df.h"

class ANS
{
public:
	std::vector<ld> ans;
	int dim;		//解向量维度
	ANS(int _dim);
	ANS(int _dim, std::vector<ld>&);
	ANS(std::vector<ld>&);
	ANS(const ANS&);
	/// @brief 计算向量的线性倍数
	/// @param k 倍数
	/// @return 
	ANS Numdot(ld k);
	ANS& operator=(const std::vector<ld>&);
	ANS& operator=(const ANS&);
	ANS operator+(const ANS&);
	ANS operator-(const ANS& b);
	bool operator<(const ANS& b);
	bool operator>(const ANS& b);
	bool operator<=(const ANS& b);
	bool operator>=(const ANS& b);
	bool operator!=(const ANS& b);
	ld& operator[](int index);
	friend ld dis(ANS&, ANS&);
	void print() const;
	
};

typedef ld(*SearchFunc)(const ANS&);



/// @brief 计算长度相同的向量的欧氏距离
/// @param a 
/// @param b 
/// @return 距离
ld dis(ANS& a, ANS& b);
ANS abs(ANS a);




