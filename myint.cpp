#define _CRT_SECURE_NO_WARNINGS
#include "myint.h"
#include<string>
#include<iostream>

myint::myint() : v(0), sign(1)
{
}

myint::myint(int n)
{
	bool is_neg = false;
	if (n < 0) { is_neg = true; n = -n; }
	v = n;
	if (is_neg)
		sign = -1;
	else
		sign = 1;
}

myint::myint(long long n)
{
	bool is_neg = false;
	if (n < 0) { is_neg = true; n = -n; }
	v = n;
	if (is_neg)
		sign = -1;
	else
		sign = 1;
}

myint::myint(const myint& m)
{
	v = m.v;
	sign = m.sign;
}

myint::myint(const mynat* m, const int s)
{
	v = m;
	sign = s;
}

myint::myint(const mynat& m, const int s)
{
	v = m;
	sign = s;
}

myint::myint(const myint* m)
{
	v = m->v;
	sign = m->sign;
}

myint::myint(const std::string& s)
{
	int pos = 0;
	if (s[0] == '-') { sign = -1; pos = 1; }
	else { sign = 1; };
	v = mynat(s.substr(pos));
}

std::string myint::to_string() const
{
	std::string ret;
	if (sign == -1)
		ret = "-";
	ret.append(v.to_string());
	return ret;
}

myint myint::operator-() const
{
	myint ret(this);
	ret.sign = -ret.sign;
	return ret;
}

myint myint::operator+(const myint& m) const
{
	myint a(this), b(m), ret;
	if (a.sign * b.sign == 1)
	{
		ret.v = a.v + b.v;
		ret.sign = a.sign;
	}
	else
	{
		ret.v = b.v - a.v;
		if (a.sign == -1)
		{
			if (a.v < b.v)
				ret.sign = 1;
			else
				ret.sign = -1;
		}
		else
		{
			if (a.v < b.v)
				ret.sign = -1;
			else
				ret.sign = 1;
		}
	}
	return ret;
}

myint myint::operator-(const myint& m) const
{
	return myint(this) + (-m);
}

myint myint::operator*(const myint& m) const
{
	return myint(v * m.v, sign * m.sign);
}

myint myint::operator/(const myint& m) const
{
	return myint(v / m.v, sign * m.sign);
}

myint myint::operator%(const myint& m) const
{
	myint ret = v % m.v;
	ret.sign = sign;
	return ret;
}

bool myint::operator>(const myint& m) const
{
	if (v > m.v && sign == 1 && m.sign == 1)
		return true;
	if (v < m.v && sign == -1 && m.sign == -1)
		return true;
	if (sign == 1 && m.sign == -1)
		return true;
	return false;
}

bool myint::operator<(const myint& m) const
{
	if (v < m.v && sign == 1 && m.sign == 1)
		return true;
	if (v > m.v && sign == -1 && m.sign == -1)
		return true;
	if (sign == -1 && m.sign == 1)
		return true;
	return false;
}

bool myint::operator>=(const myint& m) const
{
	return !(myint(this) < m);
}

bool myint::operator<=(const myint& m) const
{
	return !(myint(this) > m);
}

bool myint::operator==(const myint& m) const
{
	if (v == m.v && sign == m.sign)
		return true;
	return false;
}

bool myint::operator!=(const myint& m) const
{
	return !(myint(this) == m);
}