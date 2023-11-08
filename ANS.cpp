#include"ANS.h"

ANS::ANS(int _dim)
{
	dim = _dim;
	for (int i = 0; i < dim; i++) {
		ans.push_back(0);
	}
}

ld ANS::norm2()
{
	ld res = 0;
	for (int i = 0; i < dim; i++) {
		res += ans[i] * ans[i];
	}
	return sqrtl(res);
}


ANS::ANS(int _dim, std::vector<ld>& _ans)
{
	dim = _dim;
	for (int i = 0; i < dim; i++) {
		ans.push_back(_ans[i]);
	}
}

ANS& ANS::operator=(const std::vector<ld>& _ans)
{
	if (dim != _ans.size()) {
		printf("����ʧ�ܣ���ֵ�����ͽ�������С��һ��\n");
		return *this;
	}
	for (int i = 0; i < dim; i++)
	{
		ans[i] = _ans[i];
	}
	return *this;
}
ANS::ANS(std::vector<ld>& _ans) :ANS(_ans.size(), _ans)
{}

ld ANS::operator*(const ANS& b)
{
	ld res = 0;
	if (b.dim != dim) {
		printf("���Ȳ�һ�������������ڻ���\n");
		return res;
	}
	for (int i = 0; i < dim; i++)
	{
		res += ans[i] * b.ans[i];
	}
	return res;
}



ANS::ANS(const ANS& _ans)
{
	ans.clear();
	dim = _ans.dim;
	for (int i = 0; i < dim; i++) {
		ans.push_back(_ans.ans[i]);
	}
}
ANS& ANS::operator=(const ANS& _ans)
{
	return this->operator=(_ans.ans);
}


ANS ANS::operator+(const ANS& b)
{
	if (dim != b.dim) {
		printf("���Ȳ�һ�µ������������\n");
		return *this;
	}
	ANS tmp(dim);
	for (int i = 0; i < dim; i++)
	{
		tmp.ans[i] = ans[i] + b.ans[i];
	}
	return tmp;
}

ANS ANS::operator-(const ANS& b)
{
	if (dim != b.dim) {
		printf("���Ȳ�һ�µ������������\n");
		return *this;
	}
	ANS tmp(dim);
	for (int i = 0; i < dim; i++)
	{
		tmp.ans[i] = ans[i] - b.ans[i];
	}
	return tmp;
}

bool ANS::operator<(const ANS& b)
{
	if (dim != b.dim) {
		printf("��ͬ���ȵ��������ܱȽϴ�С\n");
		return 0;
	}
	for (int i = 0; i < dim; i++)
	{
		if (ans[i] >= b.ans[i]) {
			return 0;
		}
	}
	return 1;
}

bool ANS::operator>(const ANS& b)
{
	if (dim != b.dim) {
		printf("��ͬ���ȵ��������ܱȽϴ�С\n");
		return 0;
	}
	for (int i = 0; i < dim; i++)
	{
		if (ans[i] < b.ans[i] || fabsl(ans[i] - b.ans[i]) < INS) {
			return 0;
		}
	}
	return 1;
}

bool ANS::operator>=(const ANS& b)
{
	if (dim != b.dim) {
		printf("��ͬ���ȵ��������ܱȽϴ�С\n");
		return 0;
	}
	for (int i = 0; i < dim; i++)
	{
		if (ans[i] < b.ans[i]) {
			return 0;
		}
	}
	return 1;
}
bool ANS::operator<=(const ANS& b)
{
	if (dim != b.dim) {
		printf("��ͬ���ȵ��������ܱȽϴ�С\n");
		return 0;
	}
	for (int i = 0; i < dim; i++)
	{
		if (ans[i] > b.ans[i]) {
			return 0;
		}
	}
	return 1;
}

bool ANS::operator!=(const ANS& b)
{
	if (dim != b.dim) {
		printf("��ͬ���ȵ��������ܱȽϴ�С\n");
		return 1;
	}
	for (int i = 0; i < dim; i++)
	{
		if (fabsl(ans[i] - b.ans[i]) > INS) {
			return 1;
		}
	}
	return 0;
}

ld& ANS::operator[](int index)
{
	return ans[index];
}
ld ANS::operator[](int index) const
{
	return ans[index];
}


ANS abs(ANS a)
{
	ANS tmp(a.dim);
	for (int i = 0; i < a.dim; i++)
		tmp[i] = abs(a[i]);
	return tmp;
}


ANS ANS::Numdot(ld k)
{
	ANS tmp(dim);
	for (int i = 0; i < dim; i++) {
		tmp.ans[i] = ans[i] * k;
	}
	return tmp;
}

ld dis(ANS& a, ANS& b)
{
	if (a.dim != b.dim) {
		printf("���������Ȳ�һ�£����ܼ������\n");
		return INFINITY;
	}
	ld res = 0;
	for (int i = 0; i < a.dim; i++) {
		res += (a.ans[i] - b.ans[i]) * (a.ans[i] - b.ans[i]);
	}
	return sqrtl(res);
}


void ANS::print() const
{
	//printf("dim = %d, ", dim);
	printf("(");
	for (int i = 0; i < dim - 1; i++) {
		printf("%.6Lf,", ans[i]);
	}
	printf("%.6Lf)\n", ans[dim - 1]);
}




ANS derivative(SearchFunc target, ANS& x)
{
	ANS res(x.dim);
	for (int i = 0; i < x.dim; i++)
	{
		ANS tmp1(x), tmp2(x);
		tmp1[i] += delta / 2; tmp2[i] -= delta / 2;
		res[i] = (target(tmp1) - target(tmp2)) / delta;
	}
	return res;
}
