#include "fraction.h"
#include"myint.h"
#include<iostream>

myint gcd(const myint& a, const myint& b)
{
	// a, b > 0
	if (b != 0)
		return gcd(b, a % b);
	return a;
}

void fraction::normalize()
{
	if (b < 0)
	{
		a = -a;
		b = -b;
	}
	if (b == 0)
	{
		std::cerr << "[Divide by zero] " << this->to_string() << " 分母不能为零" << std::endl;
		return;
	}
	bool is_neg = (a < 0);
	if (is_neg) { a = -a; }
	myint g = gcd(a, b);
	a = a / g;
	b = b / g;
	if (is_neg) { a = -a; }
}

fraction::fraction() : a(0), b(1)
{
}

fraction::fraction(const myint& n) : a(n), b(1)
{
}

fraction::fraction(const fraction& m)
{
	a = m.a;
	b = m.b;
	if (b == 0)
	{
		std::clog << "[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

fraction::fraction(const fraction* m)
{
	a = m->a;
	b = m->b;
	if (b == 0)
	{
		std::clog << "[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

fraction::fraction(const myint& am, const myint& bm)
{
	a = am;
	b = bm;
	if (b == 0)
	{
		std::clog << "[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

fraction::fraction(const std::string& s)
{
	//std::clog << "[Debug] called fraction from str " << s << std::endl;
	// -a/b , a/b
	int pos = 0, n = (int)s.length();
	while (s[pos] != '/' && pos < n)
		pos++;
	//std::clog << "[Debug] pos=" << pos << std::endl;
	if (pos == n)
	{
		a = myint(s);
		b = 1;
		return;
	}
	a = myint(s.substr(0,pos));
	b = myint(s.substr(pos + 1));
	if (b == 0)
	{
		std::clog << "[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

fraction::fraction(const double f, int n)
{
	double x = f;
	if (x < 0) { x = -x; }
	int ans1 = 1, ans2 = 1;
	for (int i = 1; i <= n; i++)
	{
		double z = (i * 1.0) / x + 0.5;
		int a = (int)z;
		if (fabs((i * 1.0) / (a * 1.0) - x) < fabs((ans1 * 1.0) / (ans2 * 1.0) - x) && a <= n)
		{
			ans1 = i;
			ans2 = a;
		}
	}
	if (f < 0) { ans1 = -ans1; };
	a = ans1;
	b = ans2;
	normalize();
}

fraction::fraction(int a1, int b1)
{
	a = a1, b = b1;
	if (b == 0)
	{
		std::clog << "[Warning] creating a fraction with denominator = 0" << std::endl;
	}
}

std::string fraction::to_string() const
{
	if (a == b && b != 0)
		return std::string("1");
	if (b == 1)
		return std::string(a.to_string());
	return std::string(a.to_string() + "/" + b.to_string());
}

fraction fraction::operator-() const
{
	return fraction(-a, b);
}

fraction fraction::reciprocal() const
{
	if (a == 0)
	{
		std::cerr << "[Divide by zero] " << this->to_string() << " 分母不能为零" << std::endl;
	}
	return fraction(b, a);
}

fraction fraction::operator+(const fraction& m) const
{
	return fraction(a * m.b + b * m.a, b * m.b);
}

fraction fraction::operator-(const fraction& m) const
{
	return fraction(a * m.b - b * m.a, b * m.b);
}

fraction fraction::operator*(const fraction& m) const
{
	return fraction(a * m.a, b * m.b);
}

fraction fraction::operator/(const fraction& m) const
{
	return fraction(m.reciprocal() * this);
}

bool fraction::operator>(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b > f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator<(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b < f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator>=(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b >= f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator<=(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b <= f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator==(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b == f2.a * f1.b)
		return true;
	return false;
}

bool fraction::operator!=(const fraction& m) const
{
	fraction f1(this), f2(m);
	f1.normalize();
	f2.normalize();
	if (f1.a * f2.b != f2.a * f1.b)
		return true;
	return false;
}

fraction fraction::reduce() const
{
	fraction ret(this);
	ret.normalize();
	return ret;
}

void fraction::display() const
{
	if (b == 0)
	{
		std::cerr << "[Divide by zero] " << this->to_string() << " 分母不能为零" << std::endl;
		return;
	}
	std::cout << this->to_string() << std::endl;
}
