#pragma once
#include"df.h"
#define delta 1e-6
class ANS
{
public:
	std::vector<ld> ans;
	int dim;		//������ά��
	ANS(int _dim);
	ANS(int _dim, std::vector<ld>&);
	ANS(std::vector<ld>&);
	ANS(const ANS&);
	/// @brief �������������Ա���
	/// @param k ����
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



/// @brief ���㳤����ͬ��������ŷ�Ͼ���
/// @param a 
/// @param b 
/// @return ����
ld dis(ANS& a, ANS& b);

ANS abs(ANS a);

/// @brief ���ݶ���ֵ�ⷨ
/// @param target Ŀ�꺯��
/// @param x ��ǰ����X
/// @return �ݶ�
ANS derivative(SearchFunc target, ANS& x);