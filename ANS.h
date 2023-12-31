#pragma once
#include"df.h"
#define delta 1e-6
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
	ld norm2();
	bool operator<(const ANS& b);
	bool operator>(const ANS& b);
	bool operator<=(const ANS& b);
	bool operator>=(const ANS& b);
	bool operator!=(const ANS& b);
	ld operator*(const ANS& b);
	ld& operator[](int index);
	ld operator[](int index) const;
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

/// @brief 求梯度数值解法
/// @param target 目标函数
/// @param x 当前向量X
/// @return 梯度
ANS derivative(SearchFunc target, ANS& x);