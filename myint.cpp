#define _CRT_SECURE_NO_WARNINGS
#include "myint.h"
#include<string>
#include<iostream>

myint::myint() : v(0)
{
}

myint::myint(int n) : v((long long)n)
{
}

myint::myint(long long m)
{
	v = m;
}

myint::myint(const myint& m)
{
	v = m.v;
}

myint::myint(const myint* m)
{
	v = m->v;
}

myint::myint(const std::string& s)
{
	//std::clog << "[Debug] called myint from str " << s << std::endl;
	myint ret(0);
	int pos = 0, n = (int)s.length();
	bool is_neg = false;
	if (s[0] == '-') { is_neg = true; pos = 1; }
	while (pos < n)
	{
		int digit = s[pos] - '0';
		if (digit > 9 || digit < 0)
			break;
		ret = ret * 10;
		ret = ret + digit;
		pos++;
	}
	v = ret.v;
}

std::string myint::to_string() const
{
	char buffer[100];
	sprintf(buffer, "%lld", v);
	if (v < 0)
		sprintf(buffer, "(%lld)", v);
	return std::string(buffer);
}

myint myint::operator-() const
{
	return myint(-v);
}

myint myint::operator+(const myint& m) const
{
	return myint(v + m.v);
}

myint myint::operator-(const myint& m) const
{
	return myint(v - m.v);
}

myint myint::operator*(const myint& m) const
{
	return myint(v * m.v);
}

myint myint::operator/(const myint& m) const
{
	return myint(v / m.v);
}

myint myint::operator%(const myint& m) const
{
	return myint(v % m.v);
}

bool myint::operator>(const myint& m) const
{
	if (v > m.v)
		return true;
	return false;
}

bool myint::operator<(const myint& m) const
{
	if (v > m.v)
		return true;
	return false;
}

bool myint::operator>=(const myint& m) const
{
	if (v >= m.v)
		return true;
	return false;
}

bool myint::operator<=(const myint& m) const
{
	if (v <= m.v)
		return true;
	return false;
}

bool myint::operator==(const myint& m) const
{
	if (v == m.v)
		return true;
	return false;
}

bool myint::operator!=(const myint& m) const
{
	if (v != m.v)
		return true;
	return false;
}